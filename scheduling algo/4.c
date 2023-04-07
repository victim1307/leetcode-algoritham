#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

sem_t empty, full, mutex;

void *producer(void *arg) {
    int item;

    for (int i = 0; i < 5; i++) {
        // Produce item
        item = i;

        // Wait for an empty slot in the buffer
        sem_wait(&empty);

        // Acquire the mutex lock
        sem_wait(&mutex);

        // Add the item to the buffer
        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;
        printf("Producer produced item %d\n", item);

        // Release the mutex lock
        sem_post(&mutex);

        // Signal that a full slot is available in the buffer
        sem_post(&full);
    }

    pthread_exit(NULL);
}

void *consumer(void *arg) {
    int item;

    for (int i = 0; i < 5; i++) {
        // Wait for a full slot in the buffer
        sem_wait(&full);

        // Acquire the mutex lock
        sem_wait(&mutex);

        // Remove an item from the buffer
        item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        printf("Consumer consumed item %d\n", item);

        // Release the mutex lock
        sem_post(&mutex);

        // Signal that an empty slot is available in the buffer
        sem_post(&empty);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t producer_thread, consumer_thread;

    // Initialize the semaphores
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);

    // Create the threads
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    // Wait for the threads to finish
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    // Destroy the semaphores
    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);

    return 0;
}
