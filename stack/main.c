#define _GNU_SOURCE // asprintf
#include <stdio.h>

#include "stack.h"


int main() 
{
    Stack *my_stack = new_stack();
    for (int i = 0; i < 10; i++)
    {
        char *val;
        asprintf(&val, "salut! %i", i);
        push(&my_stack, val);

    }

    while (!is_empty(my_stack))
    {
        char *val = pop(&my_stack);
        printf("poped: %s\n", val);
    }
    printf("DONE\n");
    return 0;
}