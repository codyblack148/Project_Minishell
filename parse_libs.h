#ifndef _PARSE_LIBS_H_
#define _PARSE_LIBS_H_

int parsePath(char *dirs[]);
char *lookupPath(char **argv,char **dir); /*******/
char *lookupDir(char *s,char **dirs);
int parseCommand(char *,struct command_t *);
void printPrompt(void);
void readCommand(char *);

#endif
