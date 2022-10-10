#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

sem_t full;
sem_t empty;
pthread_t id[11];
int i = 0;
int j = 0;
int buff[10];
int item;
pthread_mutex_t mutex;

void *consumer(void *value)
{
    sem_wait(&full);
    pthread_mutex_lock(&mutex);
    item = buff[j];
    printf("i am a consumer with id %ld\n", (long)value);
    sleep(2);
    printf("i have taken my food %d\n", buff[j]);
    j--;
    pthread_mutex_unlock(&mutex);
    sem_post(&empty);
}
void *produser(void *value)
{
    sem_wait(&empty);
    pthread_mutex_lock(&mutex);
    printf("i am a producer with id %ld\n", (long)value);
    j++;
    buff[j] = j;
    sleep(1);
    printf("i have put the product %d\n", buff[j]);
    pthread_mutex_unlock(&mutex);
    sem_post(&full);
}

int main()
{
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, 3);
    pthread_mutex_init(&mutex, NULL);

    printf("producer then a customer\n");
    for (i = 0; i < 5; i++)
    {
        pthread_create(&id[i], NULL, produser, (void *)&id[i]);
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
