#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

#include <stdio.h>

#define NUM_PHILS 5

enum {THINKING, HUNGRY, EATING} state[NUM_PHILS];

pthread_mutex_t mutex_lock;
pthread_cond_t  cond_vars[NUM_PHILS];

int leftOf(int i)
{
    return ((i + NUM_PHILS - 1) % NUM_PHILS);
}

int rightOf(int i)
{
    return ((i + 1) % NUM_PHILS);
}

initialization_code()
{
    for (int i = 0; i < 5; i++)
    {
        state[i] = THINKING;
    }
}

void    test(int i)
{
    //내가 배고프고 내 이웃이 배가 고프지 않을 때, 먹는다
    if (state[i] == HUNGRY && state[leftOf(i)] != EATING && state[rightOf(i)] != EATING)
    {
        state[i] = EATING;
        pthread_cond_signal(&cond_vars[i]);
    }
}

void    pickup(int i)
{
    pthread_mutex_lock(&mutex_lock);
    state[i] = HUNGRY;
    test(i);
    if (state[i] != EATING)
    {
        pthread_cond_wait(&cond_vars[i], &mutex_lock);
    }
    pthread_mutex_unlock(&mutex_lock);
}

void    putdown(int i)
{
    pthread_mutex_lock(&mutex_lock);
    state[i] = THINKING;
    test(leftOf(i));
    test(rightOf(i));
    pthread_mutex_unlock(&mutex_lock);
}

void    think(int id)
{
    printf("%d: Now, I'm thinking...\n", id);
    usleep((1 + rand() % 50) * 10000);
}

void    eat(int id)
{
    printf("%d: Now, I'm eating...\n", id);
    usleep((1 + rand() % 50) * 10000);
}

void    *philosopher(void *param)
{
    int id;

    id = *((int *)param);
    while (1)
    {
        think(id);
        pickup(id);
        eat(id);
        putdown(id);
    }
}

void    init()
{
    int i;

    for(i = 0; i < NUM_PHILS; i++)
    {
        state[i] = THINKING;
        pthread_cond_init(&cond_vars[i], NULL);
    }
    pthread_mutex_init(&mutex_lock, NULL);
    srand(time(0));
}

int main()
{
    int i;
    pthread_t   tid;

    init();
    for (i = 0; i < NUM_PHILS; i++)
        pthread_create (&tid, NULL, philosopher, (void *)&i);
    for (i = 0; i < NUM_PHILS; i++)
        pthread_join(tid, NULL);
    return (0);
}