#ifndef _INFO_H_
#define _INFO_H_

/* The headers here */
#include <stdlib.h>
#include <unistd.h>
#include "types.h"
#include "alias.h"
#include "command.h"
#include "env.h"
#include "getline.h"
#include "error.h"
#include "history.h"
#include "list.h"
#include "string.h"
#include "tokens.h"

extern char **environ;

/**
  * struct info - shell state info
  * @interactive: arguments intersctive
  * @argc: arguments
  * @argv: arguments done
  * @file: arguments done
  * @fileno: arguments done
  * @status: arguments passed
  * @line: arguments passed
  * @lineno: arguments done
  * @tokens: arguments passed
  * @pid: arguments passed
  * @cwd: arguments passed
  * @exe: arguments passed
  * @env: arguments passed
  * @path: arguments passed
  * @aliases: arguments passed
  * @history: give arguments history
  * @commands: give arguments command
  */
struct info
{
	/* here goes the prototype */
	int argc;
	int fileno;
	char **argv;
	char *file;
	int status;
	char *line;
	size_t lineno;
	char **tokens;
	pid_t pid;
	char *cwd;
	env_t *env;
	list_t *path;
	 int interactive;
	char *exe;
	alias_t *aliases;
	history_t *history;
	cmdlist_t *commands;
};

int free_info(info_t *info);
info_t *init_info(int argc, char **argv);

#endif
