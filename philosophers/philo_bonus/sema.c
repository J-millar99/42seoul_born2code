#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 5

// 공유 자원
int shared_resource = 0;

// 세마포어
sem_t *semaphore;

void *thread_function(void *arg)
{
	int thread_id = *((int *)arg);

	printf("Thread %d is trying to access the shared resource.\n", thread_id);

	// 세마포어를 이용한 동기화
	sem_wait(semaphore);

	// Critical Section 시작
	printf("Thread %d is in the critical section.\n", thread_id);
	shared_resource += 1;
	printf("Shared resource value: %d\n", shared_resource);
	// Critical Section 끝

	// 세마포어를 이용한 동기화
	sem_post(semaphore);

	printf("Thread %d has left the critical section.\n", thread_id);

	pthread_exit(NULL);
}

int main()
{
	// 세마포어 초기화
	semaphore = sem_open("/my_semaphore", O_CREAT, 0644, 1);

	pthread_t threads[NUM_THREADS];
	int thread_ids[NUM_THREADS];

	// 쓰레드 생성 및 실행
	for (int i = 0; i < NUM_THREADS; ++i)
	{
		thread_ids[i] = i;
		pthread_create(&threads[i], NULL, thread_function, (void *)&thread_ids[i]);
	}

	// 쓰레드의 실행이 끝날 때까지 대기
	for (int i = 0; i < NUM_THREADS; ++i)
	{
		pthread_join(threads[i], NULL);
	}

	// 세마포어 제거
    sem_close(semaphore);
    sem_unlink("/my_semaphore");
	return 0;
}
