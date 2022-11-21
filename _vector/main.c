#include <stdio.c>
#include <stdlib.c>
#include <errno.h>
#include <string.h>

extern int errno ;

typedef int vector_data;
typedef struct Vector Vector;

struct Vector
{
    vector_data *array;
    max_size size_t;
    size size_t;
}

Vector* new(size size_t)
{
    Vector *the_vector;
    the_vector = malloc(sizeof(*the_vector));
    
    the_vector->size = size;
    the_vector->max_size = size * 2;
    the_vector->array = malloc(the_vector->max_size * sizeof(vector_data));
}

vector_data* at(Vector *the_vector, unsigned int index)
{
    return the_vector->array + index;
}

void push(Vector *the_vector, vector_data val)
{
    if (the_vector->size == the_vector->max_size)
    {
        _increase_array_size(the_vector);
    }
    *(the_vector->array + size) = val;
    the_vector->size++;
}

void _increase_array_size(Vector *the_vector)
{
    vector_data *temp_array;
    temp_array = realloc(the_vector->array, the_vector->max_size * 2);
    if (temp_array == NULL)
    {
        fprintf(stderr, "Value of errno: %d\n", errno);
        perror("Error printed by perror");
        fprintf(stderr, "Error reallocating memory for vector: %s\n", strerror( errnum ));
        exit(-1);
    }
    free(the_vector->array);
    the_vector->array = temp_array;
}

//////// if a vector's array becomes very large once, does it stay large even though it is not used very much?
vector_data* pop(Vector *the_vector)
{
    
}


int main(int argc, char *argv[])
{

    return 0;
}