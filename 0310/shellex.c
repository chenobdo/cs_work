#include "csapp.h"
#define MAXARGS 128

void unix_error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(0);
}

pid_t Fork(void)
{
    pid_t pid;

    if ((pid = fork()) < 0)
        unix_error("Fork error");
    return pid;
}

/* function protoypes */
void eval(char *cmdline);
int parseline(const char *cmdline, char **argv);
int builtin_command(char **argv);

int main()
{
    char cmdline[MAXARGS]; /* commond line */

    while (1) {
        /* read */
        printf("> ");
        Fgets(cmdline, MAXLINE, stdin);
        if (feof(stdin))
            exit(0);

        /* evaluate */
        eval(cmdline);
    }
}

/* eval-evaluate a commond line */
vodi eval(char *cmdline)
{
    char *argv[MAXARGS]; /* argv for evecve() */
    int bg; /* should the job run in bg or fg? */
    pid_t pid;

    bg = parseline(cmdline, argv);
    if (argv[0] == NULL)
        return; /* ignote empty line */

        if (!builtin_command(argv)) {
            if ((pid = Fork()) == 0) { /* child runs user job */
                if (execve(argv[0], argv, environ) < 0) {
                    printf("%s: Commond not found.\n", argv[0]);
                    exit(0);
                }
            }

            /* parent waits for foreground job to terminate */
            if (!bg) {
                int status;
                if (waitpid(pid, &status, 0) < 0)
                    unix_error("waitfg: waitpid error");
            }
            else
                printf("%d %s", pid, cmdline);
        }
        return;
}

int builtin_command(char **argv)
{
    if (!strcmp(argv[0], "quit"))
        exit(0);
    if (!strcmp(argv[0], "&"))
        return 1;
    return 0;
}

int parseline(const char *cmdline, char **argv)
{
    char array[MAXLINE];
    char *buf = array;
    char *delim;
    int argc;
    int bg;

    strcpy(buf, cmdline);
    buf[strlen(buf) - 1] = '  ';
    while (*buf && (*buf == '  '))
        buf++;

    argc = 0;
    while ((delim = strchr(buf, '  '))) {
        argv[argc++] = buf;
        *delim = '\0';
        buf = delim + 1;
        while (*buf && (*buf == '  '))
            buf++;
    }
    argv[argc] = NULL;

    if (argv == 0)
        return 1;

    if ((bg = (*argv[argc - 1] == '&')) != 0)
        argv[--argc] = NULL;

    return bg;
}