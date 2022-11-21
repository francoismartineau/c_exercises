#include <stdio.h>
#include <stdbool.h>
#include<unistd.h>      // sleep





void draw_line_pixel(int x, int width)
{
    for (int i = 0; i <= width; i++)
    {
        if (i <= x)
            printf("*");
        else
            printf(" ");
    }
    printf("\n");
}


int main()
{
    int width = 104;
    int x = width / 2;  // div entière
    int incr = 1;


    while (true)
    {
        x += incr;
        draw_line_pixel(x, width);
        sleep(.2);
        if (x == width || x == 0)
            incr *= -1;
    }


    return 0;
}