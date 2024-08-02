#include <errno.h> // errno
#include <stddef.h> // NULL
#include <stdio.h> // perror
#include <stdlib.h> // exit
#include <sys/mman.h> // mmap, munmap
#include <sys/signal.h> // SIGSTKSZ
#include <ucontext.h> // getcontext, makecontext, setcontext, swapcontext
#include <valgrind/valgrind.h> // VALGRIND_STACK_REGISTER

static void die(const char* message) {
    int err = errno;
    perror(message);
    exit(err);
}

static char* new_stack(void) {
    char* stack = mmap(
        NULL,
        SIGSTKSZ,
        PROT_READ | PROT_WRITE | PROT_EXEC,
        MAP_ANONYMOUS | MAP_PRIVATE,
        -1,
        0
    );
    if (stack == MAP_FAILED) {
        die("mmap stack failed");
    }
    VALGRIND_STACK_REGISTER(stack, stack + SIGSTKSZ);
    return stack;
}

static void delete_stack(char* stack) {
    if (munmap(stack, SIGSTKSZ) == -1) {
        die("munmap stack failed");
    }
}

static ucontext_t t0_ucontext;
static ucontext_t t1_ucontext;
static ucontext_t t2_ucontext;

static char* t1_stack;
static char* t2_stack;

static void t2_run(void) {
    printf("T2 should be done, switch back to T0\n");
    delete_stack(t1_stack);
    setcontext(&t0_ucontext);
}

static void t1_run(int arg0) {
    printf("Hooray! Got arg0: %d\n", arg0);
}

int main(void) {
    /* Initializes the ucontext with the current thread, this copies all its
     * registers, and a pointer to its stack (the default kernel allocated one).
     */
    getcontext(&t0_ucontext);

    /* If we setcontext or swapcontext to t0_context, it'll be as if we just
     * returned from that getcontext call. If you uncomment the line below
     * you'll be in an infinite loop!
     */
    // setcontext(&t0_ucontext);

    /* Let's create a context that'll execute the run function */
    t1_stack = new_stack();
    getcontext(&t1_ucontext);
    t1_ucontext.uc_stack.ss_sp = t1_stack;
    t1_ucontext.uc_stack.ss_size = SIGSTKSZ;
    /* Uncomment this line to switch to another context when this one ends.
     * By default the process will just exit if a thread makes it to the end
     * of the function.
     */
    // t1_ucontext.uc_link = &t2_ucontext;
    makecontext(
        &t1_ucontext, /* The ucontext to use, it must be initialized with
                       * getcontext
                       */
        (void (*)(void)) t1_run, /* The function to start executing */
        1, /* This is how many arguments we're going to pass to the function */
        42 /* This is the argument we pass, we can only pass `int`s */
    );

    t2_stack = new_stack();
    getcontext(&t2_ucontext);
    t2_ucontext.uc_stack.ss_sp = t2_stack;
    t2_ucontext.uc_stack.ss_size = SIGSTKSZ;
    makecontext(&t2_ucontext,  t2_run,  0);

    /* If we just setcontext here when we run T2 after T1 finishes, we'll
     * get into an infinite loop again. */
    // setcontext(&t1_ucontext);
    swapcontext(&t0_ucontext, &t1_ucontext);

    printf("Main is back in town\n");
    delete_stack(t2_stack);

    return 0;
}
