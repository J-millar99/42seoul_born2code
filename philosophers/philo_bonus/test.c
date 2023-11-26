# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>

void *f(void *ptr)
{
    pid_t child_pid = *((pid_t *)ptr);

    kill(child_pid, SIGTERM);
    return 0;
}

int main()
{
    pid_t child;
    pthread_t thread;

    child = fork();
    if (child == 0)
    {
        if (pthread_create(&thread, NULL, f, &child))
            printf("error\n");
        pthread_join(thread, NULL);
    }
    else
    {
        while (!waitpid(child, NULL, WNOHANG))
        {
            printf("sleeping\n");
            sleep(1);
        }
        printf("done\n");
    }
}