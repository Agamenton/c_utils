#ifndef JSON_H
#define JSON_H

#include "dict.h"
#include "list.h"
#include "string_builder.h"

char* json_list(list_t* list);
char* json_dict(dict_t* dict);

#endif