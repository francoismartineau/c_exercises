#ifndef UTILS
#define UTILS

#include <stdbool.h>

bool dir_exists(char *path);
int create_dir(char *path);
char* var_strcat(char* dest, int arg_qty, ...);

# endif