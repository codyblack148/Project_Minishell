#ifndef _MINISHELL_H_
#define _MINISHELL_H_

#define LINE_LEN 80
#define MAX_ARGS 64
#define LINE_LEN 80
#define MAX_ARGS 64
...
struct command_t {
	char *name;
	int argc;
	char *argv[MAX_ARGS];
};

...

#endif

