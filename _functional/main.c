#include <stdio.h>

void f()
{
    printf("f executed\n");
}

void g()
{
    printf("g executed\n");
}

void a(void (*some_func)(void))
{
    some_func();
    some_func = g;
    some_func();
}

int main()
{
    a(f);
}