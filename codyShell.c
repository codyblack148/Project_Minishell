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
	 char commandLine[LINE_LEN + 1];
	 struct command_t command = {NULL, 0, {NULL}};
	 int childPID, status;



//	pathv = (char *) malloc(sizeof(char) * MAX_PATH_LEN);
//  commandLine = (char *) malloc(sizeof(char) * LINE_LEN);

	parsePath(pathv);/* page 80 (parse_libs) */

	while(TRUE) {
		printPrompt();
		/* Read the command line and parse it */
		readCommand(commandLine);
		parseCommand(commandLine, &command);/*page 62-3 */
		/* Get the full path name for the file */
		command.name = lookupPath(command.argv, pathv);/* page 81 (parse_ilbs) */
		if(command.name == NULL )
		{
			/* Report Error */
			continue;
		}
		if(!strcmp(command.name,"exit") || !strcmp(command.name,"quit")){		
			break;
		}

		if ((childPID = fork()) == 0) {
			execvp(command.name,command.argv);
		}
		wait(&status);

	free(command.name);	}
printf("%s\n","codyShell terminating..." );
	free(command.name);
	free(pathv[0]);

	return 0;

     	}
