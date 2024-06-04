#ifndef DICT_H
#define DICT_H

typedef struct dict_node dict_node_t;
typedef struct dict dict_t;

struct dict_node
{
    char* key;
    char* value;
    dict_node_t* next;
};

struct dict
{
    dict_node_t* first;
    int size;
};


dict_t dict_init();
void dict_free(dict_t* dict);
void dict_add(dict_t* dict, char* key, char* value);
char* dict_get(dict_t* dict, char* key);
void dict_remove(dict_t* dict, char* key);
void dict_print(dict_t* dict);
dict_node_t* dict_get_node(dict_t* dict, int index);

#endif