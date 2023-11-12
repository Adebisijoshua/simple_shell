#ifndef TOKENS_H
#define TOKENS_H

#include <stdlib.h>
#include "quote.h"
#include "string.h"

char **sizeoftoken(const char *str);
char **tokenize_andquote(const char *str);

size_t number_tokens(const char *str);
size_t count_tokens_andquote(const char *str);

void allow_tokens(char ***tokens);

char **arrdup(char **arr);

char **arrjoin(char **arr1, char **arr2);

#endif /* TOKENS_H */
