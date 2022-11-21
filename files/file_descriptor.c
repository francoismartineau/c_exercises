#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>

#include "utils.h"

void print_console(char *msg)
{
    write(1, msg, strlen(msg));
}


int create_file(char *path)
{
    /* O_CREAT: créer si besoin
        O_RDWR: read write
        O_TRUNC: overwrite si existe
    */
    int fd = open(path, O_CREAT | O_RDWR | O_TRUNC, 0600);
    return fd;
}

int write_file(int fd, char *txt)
{
    return write(fd, txt, strlen(txt));
}

void read_file(int fd, char *buffer, size_t buffer_len)
{
    lseek(fd, 0, SEEK_SET);         // set offset to 0
    printf("Size: %i\n", (int) buffer_len);
    read(fd, buffer, buffer_len);
}

int main()
{
    print_console("Custom print\n");
    
    char d_path[80] = "./dir";
    if (!dir_exists(d_path))
    {
        create_dir(d_path);
    }

    if (dir_exists(d_path))
    {
        char *f_path = strcat(d_path, "/file.txt");
        int fd = create_file(f_path);
        if (fd == -1)
        {
            printf("File %s not created\n", f_path);
        }
        else
        {
            char *txt = "Texte dans fichier\n";
            int written_bytes = write_file(fd, txt);
            printf("Written bytes: %d\n", written_bytes);
            
            char found_txt[80];
            read_file(fd, found_txt, sizeof(found_txt));
            printf("Found in file: %s\n", found_txt);
            close(fd);            
        }
    }
    return 0;
}