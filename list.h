#ifndef LIST_H
#define LIST_H

/* headers here */
#include <stdlib.h>
#include "string.h"
#include "types.h"

/**
 * struct list - one linked list
 * @str:Not stable-allocated string
 * @next: address to the next node
 */
struct list
{
	char *str;
	struct list *next;
};
/* prototype here */
list_t *str_to_list(const char *str, char delim);
list_t *_str_to_list(list_t **tailptr, const char *str, char delim);
list_t *add_node(list_t **headptr, const char *str);
list_t *add_node_end(list_t **headptr, const char *str);
void free_list(list_t **headptr);

#endif /* list-h file with the prototype */
