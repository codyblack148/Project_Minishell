#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parse_libs.h"
#include "minishell.h"

/*
 ** #define MAX_ARGS 64    from minishell.h
 ** char *pathv[MAX_ARGS];
 */

int parsePath(char *dirs[]) /* page 80 */
{
    char *token = NULL;
    char *line = getenv("PATH");
    char *buffer = NULL;
    char *hbuffer = NULL;
    const char *sep_chars = ":";
    int n_parsed;
    char **parsed = NULL;

    if( line == NULL )
    {
        printf( "PATH environment variable not in environment\n" );
        return( 2 );
    }

    memset( dirs, 0, MAX_ARGS * sizeof(char *) );
 
    if( !(hbuffer = buffer = strdup( line )) )
    {
        printf( "Out of memory!\n" );
        return( 1 );
    }

    for( n_parsed = 0, token = strsep( &buffer, sep_chars ) 
       ; token
       ; token = strsep( &buffer, sep_chars ) )
    {
        if( n_parsed > MAX_ARGS )
        {
            printf( "Too many directories in PATH\n" );
            return( 3 );
        }

        dirs[n_parsed++] = token;
    }
    /*
     * Note: "dirs" is a global name allocated space by the compiler,
     * DO NOT free
     * dirs[0] is the memory location where the path was duplicated into
     * You need to free this pointer.
     */

    return 0;
}

char *lookupPath(char **argv,char **dir)
{
/* (page 80)
 * This function searches the directories identified by the dir
 * argument to see if argv[0] (the file name) appears there.
 * Allocate a new string, place the full path name in it, then
 * return the string.
 */

    char *result = NULL;
    char pName[MAX_PATH_LEN];
    int i;
/* Check to see if file name is already an absolute path name */
   if( *argv[0] == '/' )
   {
      /*code goes here, maybe just return dup of argv[0]?*/
   }

/*
 * Look in PATH directories.
 * Use access() to see if the file is in a dir.
 */
    for( i = 0 ; i < MAX_PATHS ; ++i )
    {
        /*code goes here, use access to see is argv[0] is in this directory*/
        /* if found and is executable, return strcat of directory and argv*/
    }

/*
 * file name not found in any path variable
 */
    fprintf( stderr, "%s command not found\n", argv[0] );
    return NULL;
}

char *lookupDir(char *s,char **dirs)
{
    char *t = NULL;
    int i, j;

    for( i = 0 ; *dirs ; ++i, ++dirs )
    {
        if( (j = strcmp( *dirs, s )) == 0 )
        {
            return *dirs;
        }
    }

    return NULL;
}

/*
 * Determine command name and construct the parameter list.
 * This function will build argv[] and set the argc value.
 * argc is the number of "tokens" or words on the command line.
 * argv[] is an array of strings (pointers to char *). The last
 * element in argv[] must be NULL. As we scan the command line
 * from the left, the first token goes in argv[0], the second in
 * argv[1], and so on. Each time we add a token to argv[],
 * we increment argc.
 * Finally, we initialize command.name
 */
int parseCommand(char *cLine, struct command_t *cmd) /* page 62-3 */
{
  int argc = 0;
  char **clPtr = &cLine;

  /* Fill argv[] */
  while( (cmd->argv[argc++] = strsep(clPtr, WHITESPACE)) != NULL);
  cmd->argv[argc--] = NULL;
  cmd->argc = argc;
}

void printPrompt() /* page 79 */
{
/*
 * Build the prompt string to have the machine name,
 * current directory, or other desired information.
 */
  promptString = ">: ";
  printf("%s", promptString);
}

/*
 * This code uses any set of I/O functions, such as those in
 * the stdio library to read the entire command line into 
 * the buffer. This implementation is greatly simplified,
 * but it deos the job.
 * NOTE:
 * Read the man page for "gets" for a suitable substitution
 */
void readCommand(char *buffer)
{
  gets(buffer);
} 