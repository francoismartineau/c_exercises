#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

void get_args(int argc, char **argv, char *str1)
{
    assert(argc >=2);
    for (int i = 0; i < argc; i++)
    {
        char *curr_arg = argv[i];
        printf("Curr arg %i: %s\n", i, curr_arg);

        if (i == 1)        
        {
            strcpy(str1, curr_arg);
        }
    }

}


void copy_str(char *dest, char *value)
{
    for (char *index = value; *index != '\0'; index++)
    {
        *dest = *index;
        dest++;
    }
    *dest = '\0';
}

void get_str(char *dest)
{
    printf("Enter new string:\n");
    char buffer[80];
    fgets(buffer, 80, stdin);
    //scanf("%s", buffer);
    printf("Buffer: %s\n", buffer);
    copy_str(dest, buffer);
}

int main(int argc, char **argv)
{
    char str1[80];
    get_args(argc, argv, str1);

    printf("str1 from arg: %s\n", str1);
    copy_str(str1, "Remplacé");
    printf("str1 from copy_str: %s\n", str1);
    get_str(str1);
    printf("str1 from get_str: %s\n", str1);
    return 0;
}