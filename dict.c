/*
dict_t dict_init();
void dict_free(dict_t* dict);
void dict_add(dict_t* dict, char* key, char* value);
char* dict_get(dict_t* dict, char* key);
void dict_remove(dict_t* dict, char* key);
void dict_print(dict_t* dict);
*/



// Path: dict.c
#include <stdlib.h>

#include "dict.h"

dict_t dict_init()
{
    dict_t dict;
    dict.first = NULL;
    dict.size = 0;
    return dict;
}

void dict_free(dict_t* dict)
{
    dict_node_t* node = dict->first;
    while (node != NULL)
    {
        dict_node_t* next = node->next;
        free(node->key);
        free(node->value);
        free(node);
        node = next;
    }
}

void dict_add(dict_t* dict, char* key, char* value)
{
    dict_node_t* node = malloc(sizeof(dict_node_t));
    node->key = key;
    node->value = value;
    node->next = NULL;
    if (dict->first == NULL)
    {
        dict->first = node;
    }
    else
    {
        dict_node_t* last = dict->first;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = node;
    }
    dict->size++;
}

char* dict_get(dict_t* dict, char* key)
{
    dict_node_t* node = dict->first;
    while (node != NULL)
    {
        if (strcmp(node->key, key) == 0)
        {
            return node->value;
        }
        node = node->next;
    }
    return NULL;
}


dict_node_t* dict_get_node(dict_t* dict, int index)
{
    dict_node_t* node = dict->first;
    for (int i = 0; i < index; i++)
    {
        if (node == NULL)
        { break; }
        node = node->next;
    }
    return node;
}


void dict_remove(dict_t* dict, char* key)
{
    dict_node_t* node = dict->first;
    dict_node_t* prev = NULL;
    while (node != NULL)
    {
        if (strcmp(node->key, key) == 0)
        {
            if (prev == NULL)
            {
                dict->first = node->next;
            }
            else
            {
                prev->next = node->next;
            }
            free(node->key);    // DEV-NOTE: not sure if free is supposed to be here, because key and value are not malloc'd in dict_add
            free(node->value);
            free(node);
            dict->size--;
            return;
        }
        prev = node;
        node = node->next;
    }
}

void dict_print(dict_t* dict)
{
    dict_node_t* node = dict->first;
    while (node != NULL)
    {
        printf("%s: %s\n", node->key, node->value);
        node = node->next;
    }
}