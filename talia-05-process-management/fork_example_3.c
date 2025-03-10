#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/wait.h>

// Function to get the physical address from /proc/self/pagemap
unsigned long get_physical_address(void *virtual_addr) {
    unsigned long page_size = getpagesize();
    unsigned long virtual_page_idx = (unsigned long)virtual_addr / page_size;
    unsigned long offset = ((unsigned long)virtual_addr % page_size);
    unsigned long long entry;
    int fd = open("/proc/self/pagemap", O_RDONLY);
    
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // Seek to the relevant entry in pagemap
    if (lseek(fd, virtual_page_idx * sizeof(entry), SEEK_SET) == -1) {
        perror("lseek");
        close(fd);
        exit(1);
    }

    // Read the entry
    if (read(fd, &entry, sizeof(entry)) != sizeof(entry)) {
        perror("read");
        close(fd);
        exit(1);
    }

    close(fd);

    // Extract the physical page number
    if ((entry & (1ULL << 63)) == 0) {  // Check if the page is present in memory
        return 0;  // Page not present
    }

    return ((entry & ((1ULL << 55) - 1)) * page_size) + offset; // Physical address
}

int main() {
    // Allocate a memory page
    int *shared_memory = mmap(NULL, getpagesize(), PROT_READ | PROT_WRITE,
                              MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (shared_memory == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    *shared_memory = 42; // Initial value
    printf("Before fork:\n");
    printf("  Virtual Address: %p\n", (void*)shared_memory);
    printf("  Physical Address: 0x%lx\n", get_physical_address(shared_memory));

    pid_t pid = fork();

    if (pid == 0) {  // Child process
        printf("\nChild Process Before Writing:\n");
        printf("  Virtual Address: %p\n", (void*)shared_memory);
        printf("  Physical Address: 0x%lx\n", get_physical_address(shared_memory));

        // Modify memory to trigger COW
        *shared_memory = 99;

        printf("\nChild Process After Writing:\n");
        printf("  Virtual Address: %p\n", (void*)shared_memory);
        printf("  Physical Address: 0x%lx\n", get_physical_address(shared_memory));

        munmap(shared_memory, getpagesize());
        exit(0);

    } else {  // Parent process
        wait(NULL);  // Wait for child to finish
        printf("\nParent Process After Child Execution:\n");
        printf("  Virtual Address: %p\n", (void*)shared_memory);
        printf("  Physical Address: 0x%lx\n", get_physical_address(shared_memory));

        munmap(shared_memory, getpagesize());
    }

    return 0;
}
