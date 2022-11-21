#include <stdio.h>


char get_mode(int argc, char **argv)
{
    char mode;
    if (argc < 2)
        show_help();
    else
    {
        mode = argv[1][0];
        if (mode != 'p' && mode != 'r')
            show_help();
    }
    return mode;
}

long unsigned* fibo_procedural(long unsigned* res, int nth)
{
    res[0] = 1;
    res[1] = 1;
    for (int i = 2; i < nth; i++)
    {
        res[i] = res[i-1] + res[i-2];
        printf("%inth: %lu\n", i, res[i]);
    }
    return res;
}

int fibo_recur(int nth)
{
    int res;
    if (nth < 2)
        res = 1;
    else
        res = fibo_recur(nth-1) + fibo_recur(nth-2);
    return res;
}

void show_help()
{
    printf("First arg: [p]rocedural / [r]ecursive\n");
}





int main(int argc, char **argv)
{
    int nth = 10000;
    char mode = get_mode(argc, argv);
    switch (mode)
    {
    case 'p':
    {

        printf("-- Procedural fibo ----\n");
        long unsigned res[nth];
        fibo_procedural(res, nth);
        break;
    }
    case 'r':
        printf("-- Recur fibo ----\n");
        for (int i = 0; i < nth; i++)
        {
            int res = fibo_recur(i);
            printf("%dth: %d\n", i, res);
        }    
        break;
    }


 
    return 0;
}