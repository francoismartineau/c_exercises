#include <stdio.h>

#include "./list.h"


int main()
{
    List *my_list = new_list();

    for (int i = 0; i < 10; i++)
    {
        push(my_list, i);
    }

    printf("size: %i\n", size(my_list));
    printf("first: %i\n", get_at(my_list, 0));

    printf("iter in order:\n");
    for (Node *n = list_iter_first(my_list); !list_iter_done(n); n = list_iter_next(n))
    {
        node_data val = get(n);
        printf("val: %i\n", val);
    }

    printf("iter in reverse:\n");
    for (Node *n = list_iter_last(my_list); !list_iter_done(n); n = list_iter_prev(n))
    {
        node_data val = get(n);
        printf("val: %i\n", val);
    }

    printf("insert 999999 at 3\n");
    insert_at(my_list, 999999, 3);

    printf("iter in order:\n");
    for (Node *n = list_iter_first(my_list); !list_iter_done(n); n = list_iter_next(n))
    {
        node_data val = get(n);
        printf("val: %i\n", val);
    }

    printf("remove at 3\n");
    remove_at(my_list, 3);

    printf("iter in order:\n");
    for (Node *n = list_iter_first(my_list); !list_iter_done(n); n = list_iter_next(n))
    {
        node_data val = get(n);
        printf("val: %i\n", val);
    }    

    return 0;
}