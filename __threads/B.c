#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>     // free

#include "lib.h"

#define THREADS_QTY 1000


void* routine(void *input)
{
    int nth_thread = *(int*)input;
    int number = randint(1, 3);
    printf("%dth thread, number: %d\n", nth_thread, number);
    free(input);
    return NULL;
}

int main()
{
    test();
    return 0;
    pthread_t threads[THREADS_QTY];
    for (int i = 0; i < THREADS_QTY; i++)
    {
        int *arg = malloc(sizeof(arg));
        *arg = i;
        pthread_create(&threads[i], NULL, &routine, arg);
    }

    for (int i = 0; i < THREADS_QTY; i++)
    {
        pthread_join(threads[i], NULL);
    }
    return 0;
}