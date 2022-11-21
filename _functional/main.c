#include <stdio.h>

void f()
{
    printf("f executed\n");
}

void a(void (*some_func)(void))
{
    some_func();
}

int main()
{
    a(f);
}