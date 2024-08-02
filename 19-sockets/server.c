#include <assert.h>
#include <errno.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define errno_exit(str)                                                        \
  do { int err = errno; perror(str); exit(err); } while (0)

#define SOCKET_PATH "example.sock"

static int fd;

void close_socket() {
  if (close(fd)) {
    errno_exit("close");
  }
  if (unlink(SOCKET_PATH)) {
    errno_exit("unlink");
  }
  exit(0);
}

void handle_signal(int signum) {
  assert(signum == SIGINT || signum == SIGTERM);
  close_socket();
}

void register_signal(int signum) {
  void (*sig_ret)(int) = signal(signum, handle_signal);
  if (sig_ret == SIG_ERR) {
    int err = errno;
    perror("signal");
    exit(err);
  }
}

int main(void) {
  register_signal(SIGINT);
  register_signal(SIGTERM);

  fd = socket(AF_UNIX, SOCK_STREAM, 0);
  if (fd == -1) {
    errno_exit("socket");
  }

  struct sockaddr_un sockaddr = {0};
  sockaddr.sun_family = AF_UNIX;
  strncpy(sockaddr.sun_path, SOCKET_PATH, sizeof(sockaddr.sun_path) - 1);

  if (bind(fd, (const struct sockaddr*) &sockaddr, sizeof(sockaddr))) {
    errno_exit("bind");
  }

  if (listen(fd, 0)) {
    errno_exit("listen");
  }

  while (true) {
    int connection_fd = accept(fd, NULL, NULL);
    if (connection_fd == -1) {
      errno_exit("accept");
    }

    const char *msg = "Hello there!";
    ssize_t len = strlen(msg) + 1;
    ssize_t bytes_written = write(connection_fd, msg, len);
    if (bytes_written == -1) {
      errno_exit("write");
    }
    else if (bytes_written != len) {
      dprintf(2, "write: Unexpected partial result");
      exit(1);
    }

    if (close(connection_fd)) {
      errno_exit("close");
    }
  }
  
  return 0;
}
