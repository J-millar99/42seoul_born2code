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
    int i = 0;
    while(i < 5)
    {
        printf("@@\n");
        sleep(1);
        i++;
    }
    return 0;
}

int main()
{
    pid_t child;
    pthread_t thread;

    child = fork();
    if (child == 0)
    {
        if (pthread_create(&thread, NULL, f, 0))
            printf("error\n");
        pthread_detach(thread);
        exit(0);
    }
    else
    {
        sleep(1);
        kill(child, SIGTERM);
        sleep(5);
    }
}