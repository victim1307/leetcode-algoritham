#include <stdio.h>
#include <pthread.h>

int shared_resource = 0;

void *thread_func(void *arg) {
    int thread_num = *(int *)arg;

    for (int i = 0; i < 1000000; i++) {
        // Critical section
        shared_resource++;
        // End critical section
    }

    printf("Thread %d finished\n", thread_num);

    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;
    int thread1_num = 1, thread2_num = 2;

    pthread_create(&thread1, NULL, thread_func, (void *)&thread1_num);
    pthread_create(&thread2, NULL, thread_func, (void *)&thread2_num);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Shared resource value: %d\n", shared_resource);

    return 0;
}
