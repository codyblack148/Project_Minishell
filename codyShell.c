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
	char *commandLine[LINE_LEN];
	struct command_t command = {NULL, 0, {NULL}};
	int childPID, w;

	parsePath(pathv);/* page 80 (parse_libs) */

	while(TRUE) {
		printPrompt();
		/* Read the command line and parse it */
		readCommand(commandLine);
		parseCommand(commandLine, &command);/*page 62-3 */
		/* Get the full path name for the file */
		command.name = lookupPath(command.argv, pathv);/* page 81 (parse_ilbs) */
		if (strcmp(command.name,"exit") == 0 || strcmp(command.name,"quit") == 0 ) {
			break; //exit while loop. Terminate shell.
		}
		if(command.name == NULL )
		{
			/* Report Error */
			printf("%s\n","Your face is NULL, command failed" );
			continue;
		}
		if ((childPID = fork()) == 0) {
			execvp(command.name,command.argv);
			free(command.name);
		}
	  if ((w=(wait(NULL))) == -1) {
	  	printf("%s\n","Error in child process. Terminating..." );
			return -1;
	  }
		else if (w > 0) {
			free(command.name);
		}

	}
printf("%s\n","codyShell terminating..." );
	free(pathv[0]);

	return 0;
}
