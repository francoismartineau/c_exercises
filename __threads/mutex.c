#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>     // free
#include <unistd.h>     // sleep


pthread_mutex_t mutex;

void* r1()
{
    pthread_mutex_lock(&mutex);
    printf("r1 locked\n");
    sleep(3);
    printf("r1 unlocked mutex\n");
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void* r2()
{
    printf("r2 begin\n");
    pthread_mutex_lock(&mutex);
    printf("r2 locked\n");
    printf("r2 unlocked\n");
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main()
{
    pthread_mutex_init(&mutex, NULL);

    pthread_t t[2];
    pthread_create(&t[0], NULL, &r1, NULL);
    sleep(.1);
    pthread_create(&t[1], NULL, &r2, NULL);


    pthread_join(t[0], NULL);
    pthread_join(t[1], NULL);

    pthread_mutex_destroy(&mutex);
    return 0;
}