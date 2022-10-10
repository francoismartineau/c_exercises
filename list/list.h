#ifndef LIST
#define LIST

#include <stdbool.h>

typedef int node_data;
typedef struct Node Node;
typedef struct List List;

Node* new_node();
List* new_list();

int size(List *the_list);

void insert(List *the_list, node_data val);
void push(List *the_list, node_data val);
void insert_at(List *the_list, node_data val, int index);
void remove_at(List *the_list, int index);
node_data get_at(List *the_list, int index);

Node* list_iter_first(List *the_list);
Node* list_iter_last(List *the_list);
Node* list_iter_next(Node *the_node);
Node* list_iter_prev(Node *the_node);
bool list_iter_done(Node *the_node);
node_data get(Node *the_node);

#endif