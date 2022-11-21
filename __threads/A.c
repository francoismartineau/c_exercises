#include <stdio.h>
#include <pthread.h>

void* routine()
{
    printf("Hello, I'm in a thread\n");
    return NULL;
}

int main()
{
    pthread_t t1;
    // pointer to t1
    // attributes: can be NULL
    // (pointer to) function to execute
    // function paramters: can be NULL
    pthread_create(&t1, NULL, &routine, NULL);

    // t1
    // return: can be NULL
    pthread_join(t1, NULL);
    return 0;
}