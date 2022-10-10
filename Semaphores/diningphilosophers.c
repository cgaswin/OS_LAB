#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
sem_t forks[5];
pthread_t ids[5];
int phi[5];
void *philosopher(void *value)
{
    int item = *(int *)value;
    printf("\nphilosopher %d is going to eat", item);
    sem_wait(&forks[item]);
    printf("\nphilosopher %d took fork %d", item, item);
    sem_wait(&forks[(item + 1) % 5]);
    printf("\nphilosopher %d took fork %d", item, (item + 1) % 5);
    printf("\nphilosopher %d started eating", item);
    sleep(1);
    sem_post(&forks[item]);
    printf("\nphilosopher %d put down fork %d", item, item);
    sem_post(&forks[(item + 1) % 5]);
    printf("\nphilosopher %d put down fork %d", item, (item + 1) % 5);
    sleep(1);
    printf("\nphilosopher %d stoped eatting", item);
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
        pthread_create(&ids[i], NULL, philosopher, (void*)&i);
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
