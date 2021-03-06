#ifndef _MINISHELL_H_
#define _MINISHELL_H_

#define LINE_LEN 80
#define MAX_ARGS 64
#define MAX_DIR_LEN 80
#define MAX_PATH_LEN 80
#define MAX_PATHS 64
#define MAX_PROMPT_LENGTH 64
#define WHITESPACE " ,\t\n"
#define TRUE 1

struct command_t {
	char *name;
	int argc;
	char *argv[MAX_ARGS];
};

int parsePath(char *dirs[]);
char *lookupPath(char **argv,char **dir); /*******/
char *lookupDir(char *s,char **dirs);
int parseCommand(char *,struct command_t *);
void printPrompt(void);
void readCommand(char *);

#endif
