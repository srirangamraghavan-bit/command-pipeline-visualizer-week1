#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>

static void handle_sigint(int sig)
{
    (void)sig;
    printf("\n");
    fflush(stdout);
}

static void handle_sigchld(int sig)
{
    (void)sig;

    while (waitpid(-1, NULL, WNOHANG) > 0)
    {
    }
}

void initialize_signals(void)
{
    signal(SIGINT, handle_sigint);
    signal(SIGCHLD, handle_sigchld);
}
