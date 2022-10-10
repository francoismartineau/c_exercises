#ifndef STACK
#define STACK

#include <stdbool.h>

typedef char* stack_data;         // not in main because referenced here. But you need to edit it here?
typedef struct Stack Stack;

Stack* new_stack();
void push(Stack **the_stack, stack_data val);
stack_data top(Stack *the_stack);
stack_data pop(Stack **the_stack);
bool is_empty(Stack *the_stack);

#endif