#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void);

int main()
{
    char *token = NULL;
    const char *line = "LINE TO BE SEPARATED";
    char *buffer = NULL;
    char *hbuffer = NULL;
    const char *sep_chars = " ";
    int n_parsed, n_alloc, i;
    char **parsed = NULL;

    if( !(hbuffer = (buffer = strdup( line ))) )
    {
        printf( "Out of memory!\n" );
        exit( 1 );
    }

    for( n_parsed = 0, n_alloc = 0, token = strsep( &buffer, sep_chars ) 
       ; token
       ; token = strsep( &buffer, sep_chars ) )
    {
        if( n_alloc == n_parsed )
        {
            n_alloc += 10;
            parsed = (char **)realloc( (void *)parsed, n_alloc * sizeof(char *) );

            if( !parsed )
            {
                printf( "Out of memory!\n" );
                exit( 1 );
            }
        }

        parsed[n_parsed++] = token;
    }

    if( n_alloc != n_parsed )
    {
        parsed = (char **)realloc( (void *)parsed, n_parsed * sizeof(char *) );

        if( !parsed )
        {
            printf( "Out of memory!\n" );
            exit( 1 );
        }
    }

    for( i = 0 ; i != n_parsed ; ++i )
    {
        printf( "parsed[%2d] = \"%s\"\n", i, parsed[i] );
    }

    free( parsed );
    free( hbuffer );

    return 0;
}

