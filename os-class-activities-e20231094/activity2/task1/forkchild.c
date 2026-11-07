/* forkchild.c — Process creation with fork() and exec() */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    printf("Parent process (PID: %d) — creating child...\n", getpid());
    fflush(stdout);

    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) {
        /* ---- CHILD PROCESS ---- */
        printf("Child process (PID: %d, Parent PID: %d)\n", getpid(), getppid());
        printf("Child: sleeping 30s — observe the process tree now!\n");
        fflush(stdout);
        sleep(30);

        printf("Child: now executing 'ls -la'...\n");
        fflush(stdout);

        execlp("ls", "ls", "-la", NULL);

        /* Only reached if execlp fails */
        perror("execlp");
        exit(EXIT_FAILURE);
    }
    else {
        /* ---- PARENT PROCESS ---- */
        int status;
        printf("Parent: waiting for child (PID: %d) to finish...\n", pid);
        fflush(stdout);

        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            printf("Parent: child exited with status %d\n", WEXITSTATUS(status));
        }
        printf("Parent: done.\n");
    }
    return 0;
}
