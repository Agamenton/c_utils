/*
list_t list_init();
void list_free(list_t* list);
void list_add(list_t* list, char* value);
char* list_get(list_t* list, int index);
void list_remove(list_t* list, int index);
void list_print(list_t* list);
*/

// Path: list.c
#include <stdlib.h>

#include "list.h"

list_t list_init()
{
    list_t list;
    list.first = NULL;
    list.size = 0;
    return list;
}

void list_free(list_t* list)
{
    list_node_t* node = list->first;
    while (node != NULL)
    {
        list_node_t* next = node->next;
        free(node->value);
        free(node);
        node = next;
    }
}

void list_add(list_t* list, char* value)
{
    list_node_t* node = malloc(sizeof(list_node_t));
    node->value = value;
    node->next = NULL;
    if (list->first == NULL)
    {
        list->first = node;
    }
    else
    {
        list_node_t* last = list->first;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = node;
    }
    list->size++;
}

char* list_get(list_t* list, int index)
{
    list_node_t* node = list->first;
    for (int i = 0; i < index; i++)
    {
        node = node->next;
    }
    return node->value;
}

void list_remove(list_t* list, int index)
{
    list_node_t* node = list->first;
    if (node == NULL)
    {
        return;
    }

    if (index == 0)
    {
        list->first = node->next;
        free(node->value); // ?
        free(node);
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            if (node->next == NULL) { return; }
            node = node->next;
        }
        list_node_t* next = node->next->next;
        free(node->next->value);
        free(node->next);
        node->next = next;
    }
    list->size--;
}

void list_print(list_t* list)
{
    list_node_t* node = list->first;
    while (node != NULL)
    {
        printf("%s\n", node->value);
        node = node->next;
    }
}
