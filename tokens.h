#ifndef TOKENS_H
#define TOKENS_H

#include <stdlib.h>
#include "quote.h"
#include "string.h"


char **tokenize_noquote(const char *str);
size_t count_tokens(const char *str);
char **tokenize(const char *str);
size_t count_tokens_noquote(const char *str);
void free_tokens(char ***tokens);
char **arrjoin(char **arr1, char **arr2);
char **arrdup(char **arr);

#endif
