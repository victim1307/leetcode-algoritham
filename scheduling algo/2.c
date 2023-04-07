#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int shared_resource = 0;
sem_t sem;

void *thread_func(void *arg) {
    int thread_num = *(int *)arg;

    for (int i = 0; i < 1000000; i++) {
        // Wait on the semaphore
        sem_wait(&sem);

        // Critical section
        shared_resource++;
        // End critical section

        // Signal the semaphore
        sem_post(&sem);
    }

    printf("Thread %d finished\n", thread_num);

    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;
    int thread1_num = 1, thread2_num = 2;

    // Initialize the semaphore with value 1
    sem_init(&sem, 0, 1);

    pthread_create(&thread1, NULL, thread_func, (void *)&thread1_num);
    pthread_create(&thread2, NULL, thread_func, (void *)&thread2_num);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Shared resource value: %d\n", shared_resource);

    // Destroy the semaphore
    sem_destroy(&sem);

    return 0;
}
