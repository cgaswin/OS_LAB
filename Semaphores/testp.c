#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

pthread_t id[11];
sem_t empty;
sem_t full;

int i = 0, j = 0;
int buff[10];
int buffer = 0;
int item;

pthread_mutex_t mutex;

void *producer(void *value)
{
    sem_wait(&empty);
    pthread_mutex_lock(&mutex);

    printf("Producer with id: %ld\n", (long)value);
    j++;
    buff[j] = j;
    sleep(1);
    printf("Producer produced item: %d\n", buff[j]);

    pthread_mutex_unlock(&mutex);
    sem_post(&full);
}

void *consumer(void *value)
{
    sem_wait(&full);
    pthread_mutex_lock(&mutex);

    item = buff[j];
    printf("Consumer with id: %ld\n", (long)value);
    sleep(2);
    printf("Consumer consumed item: %d\n", buff[j]);
    j--;

    pthread_mutex_unlock(&mutex);
    sem_post(&empty);
}

int main()
{
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, 3);
    pthread_mutex_init(&mutex, NULL);

    printf("Producer then consumer...\n");
    for (i = 0; i < 5; i++)
    {
        pthread_create(&id[i], NULL, producer, (void *)&id[i]);
    }
    for (i = 5; i < 10; i++)
    {
        pthread_create(&id[i], NULL, consumer, (void *)&id[i]);
    }
    for (i = 0; i < 5; i++)
    {
        pthread_join(id[i], NULL);
    }
    for (i = 0; i < 10; i++)
    {
        pthread_join(id[i + 1], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&full);
    sem_destroy(&empty);

    return 0;
}