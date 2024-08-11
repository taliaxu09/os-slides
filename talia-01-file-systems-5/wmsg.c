struct foomsg {
    u_int32_t len;
};

void send_foo(char *contents) {
    // Calculate the message length
    int content_len = strlen(contents);
    int msglen = sizeof(struct foomsg) + content_len;

    // Allocate buffer
    char *buf = malloc(msglen);
    if (buf == NULL) {
        perror("Failed to allocate buffer");
        return;
    }

    struct foomsg *fm = (struct foomsg *)buf;
    fm->len = htonl(content_len);
    memcpy(buf + sizeof(struct foomsg), contents, content_len);

    // Write to the output socket
    if (write(outsock, buf, msglen) == -1) {
        perror("Failed to write to socket");
    }

    free(buf);
}
