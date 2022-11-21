#include <stdio.h>
#include <assert.h>     // assert
#include <string.h>     // strcpy

#include "utils.h"

#define A_SIZE 80

void get_args(int argc, char *argv[], char *file_name, char *text) 
{
    assert(argc > 2);
    strcpy(file_name, argv[1]);
    strcpy(text, argv[2]);
    printf("Text: %s\n", text);
    printf("File_name: %s\n", file_name);
}

FILE* create_file(char *path)
{
    printf("new file: %s\n", path);
    FILE *fp = fopen(path, "w+");
    return fp;
}

void write_file(FILE* fp, char *text)
{
    fprintf(fp, "%s", text);
    printf("write file: %s\n", text);
}

void read_file(FILE* fp, char *found_text)
{
    fseek(fp, 0, SEEK_SET);
    fgets(found_text, A_SIZE, fp);
}


int main(int argc, char *argv[])
{
    char f_name[A_SIZE];
    char text[A_SIZE];
    get_args(argc, argv, f_name, text);


    FILE *fp = NULL;
    char *d_path = "dir";
    if (!dir_exists(d_path))
    {
        create_dir(d_path);
    }
    if (dir_exists(d_path))
    {
        char f_path[A_SIZE];
        var_strcat(f_path, 3, d_path, "/", f_name);     // custom function
        //sprintf(f_path, "%s/%s", d_path, f_name);     // works
        fp = create_file(f_path);
    }
    if (fp != NULL)
    {
        write_file(fp, text);
        char found_text[A_SIZE];
        read_file(fp, found_text);
        printf("Found text: %s\n\n", found_text);
        fclose(fp);
    }
    else
    {
        printf("File not created.\n");
    }

    return 0;
}