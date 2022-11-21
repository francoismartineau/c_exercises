#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>     // free
#include <limits.h>     // INT_MAX
#include <unistd.h>     // sleep
#include "lib.h"

#define THREADS_QTY 99999

//#define USE_MUTEX

pthread_mutex_t mutex;

struct routine_arg {
    int nth;
    int *sum;
};

void add_one_inefficiently(int *val)
{
    (*val)++;
    for (int i = 0; i < 10000; i++)
    {
        (*val)--;
        (*val)++;
    }
}

void* routine(void *input)
{
    #ifdef USE_MUTEX
    pthread_mutex_lock(&mutex);
    #endif
    struct routine_arg arg = *(struct routine_arg*) input;


    add_one_inefficiently(arg.sum);
    
    //int random_n = randint(1, 3);
    //printf("%dth thread, sum: %d,  random_n: %d\n", arg.nth, *arg.sum, random_n);
    free(input);
    
    #ifdef USE_MUTEX
    pthread_mutex_unlock(&mutex);
    #endif
    return NULL;
}

int main()
{
    pthread_t threads[THREADS_QTY];
    struct routine_arg *thread_args[THREADS_QTY];
    pthread_mutex_init(&mutex, NULL);

    int sum = 0;

    int local_sum = 0;
    for (int i = 0; i < THREADS_QTY; i++)
    {
        thread_args[i] = malloc(sizeof(struct routine_arg));
        thread_args[i]->nth = i;
        thread_args[i]->sum = &sum;
        //if (i > 50000)
        //    printf("thread_args[i]->nth: %d\n", thread_args[i]->nth);
        if (pthread_create(&threads[i], NULL, &routine, thread_args[i]) != 0)
            printf("Thread %d not created\n", i);
        else
            local_sum++;
        //sleep(.01);
    }

    for (int i = 0; i < THREADS_QTY; i++)
    {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    printf("-------\n Sum: %d, Local sum: %d\n", sum, local_sum);
    char *success = sum == local_sum ? "success": "failed";
    printf("Res: %s\n", success);
    return 0;
}