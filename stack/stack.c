#include <stdlib.h>
#include <stdio.h>

#include "stack.h"



struct Stack
{
    stack_data val;
    Stack *next;
};


Stack* new_stack()
{
    Stack *the_stack;
    the_stack = malloc(sizeof(*the_stack));
    the_stack->next = NULL;
    return the_stack;
}

void push(Stack **the_stack, stack_data val)
{
    Stack *top_stack = new_stack();
    top_stack->next = *the_stack;
    top_stack->val = val;
    *the_stack = top_stack;
    return;
}

stack_data top(Stack *the_stack)
{
    return the_stack->val;;
}

stack_data pop(Stack **the_stack)
{
    stack_data val = top(*the_stack);
    if ((*the_stack)->next)
    {
        Stack *temp_stack = *the_stack;
        *the_stack = (*the_stack)->next;
        free(temp_stack);
    }
    return val;
}

bool is_empty(Stack *the_stack)
{
    return !(the_stack->next);
}