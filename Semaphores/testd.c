#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

sem_t forks[5];
pthread_t ids[5];
int phi[5];

void *philosopher(void *value)
{
    int item = *(int *)value;
    printf("Philosopher %d is going to eat.\n", item);
    sem_wait(&forks[item]);
    printf("Philosopher %d took fork %d\n", item, item);
    sem_wait(&forks[(item + 1) % 5]);
    printf("Philosopher %d took fork %d\n", item, (item + 1) % 5);

    sleep(1);

    sem_post(&forks[item]);
    printf("Philosopher %d put down fork %d", item, item);
    sem_post(&forks[(item + 1) % 5]);
    printf("Philosopher %d put down fork %d", item, (item + 1) % 5);

    sleep(1);

    printf("Philosopher %d has stopped eating.", item);
}

int main()
{
    int i;
    for (i = 0; i < 5; i++)
    {
        sem_init(&forks[i], 0, 1);
    }
    for (i = 0; i < 5; i++)
    {
        ids[i] = i;
        pthread_create(&ids[i], NULL, philosopher, (void *)&ids[i]);
    }
    for (i = 0; i < 5; i++)
    {
        pthread_join(ids[i], NULL);
    }
    for (i = 0; i < 5; i++)
    {
        sem_destroy(&forks[i]);
    }

    return 0;
}