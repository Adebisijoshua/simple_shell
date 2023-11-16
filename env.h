#ifndef _ENV_H_
#define _ENV_H_

/* headers goes here */
#include <stdlib.h>
#include "string.h"
#include "dict.h"
#include "types.h"

/* prototype here */
typedef dict_t env_t;
env_t *_env_to_dict(env_t **tailptr, char **env);
char **dict_to_env(env_t *head);
env_t *env_to_dict(char **env);


#endif
