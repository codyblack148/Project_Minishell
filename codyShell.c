#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "minishell.h"




int main(void);

int main(void)
{
	 char *pathv[MAX_PATH_LEN];
	 char *commandLine;
	 struct command_t command = {NULL, 0, {NULL}};
	 int childPID, status;
	 char *cwd = getcwd(NULL, MAX_DIR_LEN);



//	pathv = (char *) malloc(sizeof(char) * MAX_PATH_LEN);
	commandLine = (char *) malloc(sizeof(char) * LINE_LEN);

	parsePath(pathv);/* page 80 (parse_libs) */

	while(TRUE) {
		printPrompt();
		/* Read the command line and parse it */
		readCommand(commandLine);
		parseCommand(commandLine, &command);/*page 62-3 */
		/* Get the full path name for the file */
		command.name = lookupPath(command.argv, pathv);/* page 81 (parse_ilbs) */
		if(!strcmp(command.name, "cd")) {
				if(chdir(command.argv[1]) == 0)
						getcwd(cwd, MAX_DIR_LEN);
				else
						perror("Cannot change directory");
					}
		if(command.name == NULL )
		{
			/* Report Error */
			continue;
		}
		if ((childPID = fork()) == 0) {
			execvp(command.name,command.argv);
		}
		wait(&status);

	free(command.name);	}
printf("%s\n","codyShell terminating..." );
	free(commandLine);

	return 0;

     	}
