#ifndef LIST_H
#define LIST_H

typedef struct list_node list_node_t;
typedef struct list list_t;


struct list_node
{
    char* value;
    list_node_t* next;
};

struct list
{
    list_node_t* first;
    int size;
};


list_t list_init();
void list_free(list_t* list);
void list_add(list_t* list, char* value);
char* list_get(list_t* list, int index);
void list_remove(list_t* list, int index);
void list_print(list_t* list);

#endif