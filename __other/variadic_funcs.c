#include <stdio.h>
#include <stdarg.h>

void var_function(int arg_qty, ...)
{
    va_list args;
    va_start(args, arg_qty);

    char *arg;
    for (int i = 0; i < arg_qty; i++)
    {
        arg = va_arg(args, char*);
        printf("%s\n", arg);
    }
    va_end(args);    
}

int main()
{
    var_function(3, "ok", "okok", "doko");
}