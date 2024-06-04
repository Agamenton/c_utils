#include "json.h"

char* json_list(list_t* list)
{
    string_builder builder = string_builder_init();
    string_builder_append_char(&builder, '[');
    for (int i = 0; i < list->size; i++)
    {
        char* value = list_get(list, i);
        string_builder_append(&builder, value);
        if (i < list->size - 1)
        {
            string_builder_append_char(&builder, ',');
        }
    }
    string_builder_append_char(&builder, ']');
    return string_builder_to_string(&builder);
}


char* json_dict(dict_t* dict)
{
    string_builder builder = string_builder_init();
    string_builder_append_char(&builder, '{');
    for (int i = 0; i < dict->size; i++)
    {
        dict_node_t* node = dict_get_node(dict, i);
        if (node == NULL)
        { return ""; } // TODO: error handling, for now just return empty string

        string_builder_append(&builder, node->key);
        string_builder_append_char(&builder, ':');
        string_builder_append(&builder, node->value);

        if (i < dict->size - 1)
        { string_builder_append_char(&builder, ','); }
    }
    string_builder_append_char(&builder, '}');
    return string_builder_to_string(&builder);
}