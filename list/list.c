#include <stdlib.h>
#include <stdbool.h>

#include "./list.h"

struct Node
{
    node_data val;
    Node *prev;
    Node *next;
};

struct List
{
    Node *first;
    Node *last;
    int size;
};

Node* new_node()
{
    Node *the_node;
    the_node = malloc(sizeof(Node));
    return the_node;
}

List* new_list()
{
    List *the_list;
    the_list = malloc(sizeof(List));
    the_list->size = 0;
    
    Node *first = new_node();
    the_list->first = first;

    Node *last = new_node();
    the_list->last = last;

    the_list->first->prev = NULL;
    the_list->first->next = the_list->last;
    the_list->last->prev = the_list->first;
    the_list->last->next = NULL;

    return the_list;
}

int size(List *the_list)
{
    return the_list->size;
}

void insert(List *the_list, node_data val)
{
    Node *fresh_node = new_node();
    fresh_node->val = val;

    fresh_node->prev = the_list->first;
    fresh_node->next = the_list->first->next;

    the_list->first->next->prev = fresh_node;
    the_list->first->next = fresh_node;

    the_list->size++;
}

void push(List *the_list, node_data val)
{
    Node *fresh_node = new_node();
    fresh_node->val = val;

    fresh_node->prev = the_list->last->prev;
    fresh_node->next = the_list->last;

    the_list->last->prev->next = fresh_node;
    the_list->last->prev = fresh_node;

    the_list->size++;
}

void insert_at(List *the_list, node_data val, int index)
{
    Node *fresh_node = new_node();
    fresh_node->val = val;

    Node *found_node;
    found_node = the_list->first;

    for (int i = 0; i <= index; i++)
    {
        found_node = found_node->next;
    }
    
    fresh_node->prev = found_node->prev;
    fresh_node->next = found_node;

    found_node->prev->next = fresh_node;
    found_node->prev = fresh_node;

    the_list->size++;
}

void remove_at(List *the_list, int index)
{
    Node *found_node;
    found_node = the_list->first;

    for (int i = 0; i <= index; i++)
    {
        found_node = found_node->next;
    }    

    found_node->prev->next = found_node->next;
    found_node->next->prev = found_node->prev;

    free(found_node);

    the_list->size--;
}

node_data get_at(List *the_list, int index)
{
    Node *found_node;
    found_node = the_list->first;

    for (int i = 0; i <= index; i++)
    {
        found_node = found_node->next;
    }

    return found_node->val;    
}


Node* list_iter_first(List *the_list)
{
    return the_list->first->next;
}

Node* list_iter_last(List *the_list)
{
    return the_list->last->prev;
}

Node* list_iter_next(Node *the_node)
{
    return the_node->next;
}

Node* list_iter_prev(Node *the_node)
{
    return the_node->prev;
}

bool list_iter_done(Node *the_node)
{
    return !(the_node->prev) || !(the_node->next);
}

node_data get(Node *the_node)
{
    return the_node->val;
}