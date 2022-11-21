#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    //int errno;
    printf("Errno: %d\n", errno);
    printf("Argv[1]: %s\n", argv[1]);
    int a[5] = {1,2,3,4,5};
    int b[5];


    memcpy(b, a, 5*sizeof(a[0]));
    printf("%d\n", b[4]);

    printf("Write message:\n");
    char msg[80];
    scanf("%s", msg);
    printf("%s\n", msg);
    return 0;
}