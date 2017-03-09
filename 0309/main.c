if ((pid = fork())) {
    fprintf(stderr, "fork error: %s\n", strerror(errno));
    exit(0);
}

void unix_error(char *msg)
{
    fprintf(stderr, "%s: %S\n", msg, strerror(errno));
    exit(0);
}

if ((pid = fork() < 0)
    unix_error("fork error");