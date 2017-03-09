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

pid_t Fork(void)
{
    pid_t pid;

    if ((pid = fork()) < 0)
        unix_error("Fork error");
    return pid;
}

#include <unistd.h>
#include <sys/types.h>

pid_t getpid(void);
pid_t getppid(void);