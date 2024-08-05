int main() {
    FILE *file;
    file = fopen("test.txt", "r");
    
    pid_t pid = fork();
     
    if (pid == 0) {
        char line[256];
        if (fgets(line, sizeof(line), file) != NULL) {
            printf("Child read: %s", line);
        }
    } else {
        char line[256];
        if (fgets(line, sizeof(line), file) != NULL) {
            printf("Parent read: %s", line);
        }
    }
}

