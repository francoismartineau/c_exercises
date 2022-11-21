#include <sys/stat.h>
#include <stdarg.h>
#include <string.h>

#include "utils.h"

bool dir_exists(char *path)
{
    struct stat sb;
    return stat(path, &sb) == 0 && S_ISDIR(sb.st_mode);

}

int create_dir(char *path)
{
    return mkdir(path, 0700);
}

char* var_strcat(char* dest, int arg_qty, ...)
{
    va_list args;
    va_start(args, arg_qty);            // last named argument: arg_qty
    for (int i = 0; i < arg_qty; i++)
    {
        char *arg = va_arg(args, char*);
        if (i == 0)
            strcpy(dest, arg);
        else
            strcat(dest, arg);
    }
    va_end(args);
    return dest;
}