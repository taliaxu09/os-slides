#define _POSIX_C_SOURCE 200809L

#include <signal.h>
#include <unistd.h>

static void on_sigint(int signo)
{
    (void)signo;

    const char message[] = "stopping\n";

    write(STDOUT_FILENO, message, sizeof message - 1);
    //_exit(0);
}

int main(void)
{
    struct sigaction action = {0};

    action.sa_handler = on_sigint;
    sigemptyset(&action.sa_mask);
    sigaction(SIGINT, &action, NULL);

    for (;;) {
        pause();
    }
}
