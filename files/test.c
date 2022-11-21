#include <stdio.h>
#include <string.h>
#include "utils.h"

int main()
{
    //char txt[80] = "";
    //var_strcat(txt, 4, "Sal", "ut!", " Genile", " Guib");
    char str[800];
    sprintf(str, "%s/%s/%s", "ok", "okok", "papa");
    printf("String: %s\n", str);
    return 0;
}