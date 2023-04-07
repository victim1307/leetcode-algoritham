#include <stdio.h>
#include <pthread.h>

int turn = 0;
int flag[2] = {0, 0};

void *thread_func(void *arg) {
    int thread_num = *(int *)arg;

    // Enter critical section
    flag[thread_num] = 1;
    turn = 1 - thread_num;

    while (flag[1 - thread_num] == 1 && turn == 1 - thread_num) {}

    printf("Thread %d entered critical section\n", thread_num);

    // Simulate some work in the critical section
    for (int i = 0; i < 1000000; i++) {}

    printf("Thread %d exiting critical section\n", thread_num);

    // Exit critical section
    flag[thread_num] = 0;

    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;
    int thread1_num = 0, thread2_num = 1;

    pthread_create(&thread1, NULL, thread_func, (void *)&thread1_num);
    pthread_create(&thread2, NULL, thread_func, (void *)&thread2_num);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
