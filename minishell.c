#include "minishell.h"

... 

int main(void);

int main(void)
{
	char **pathv;

	...

	parsePath(pathv);/* page 80 (parse_libs) */

	while(TRUE) { /*probably need #define TRUE 1*/
		printPrompt();/* page 79 */
		/* Read the command line and parse it */
		readCommand(commandLine,&command);/* page 80 (fgets??) */
		...
		parseCommand(commandLine, &command);/*page 62-3 */
		...
		/* Get the full path name for the file */
		command.name = lookupPath(command.argv, pathv);/* page 81 (parse_ilbs) */
		if(command.name == NULL )
		{
			/* Report Error */
			continue;
		}
		/* Create child and execute the command */
		/* page 64-65 */
		...
		/* Wait for the child to terminate */
		/* page 65 */
		...
	}

	/* shell termination */
	/* free ALL allocated storage (THAT YOU ALLOCATED*/
	...
	
	return 0;
}
