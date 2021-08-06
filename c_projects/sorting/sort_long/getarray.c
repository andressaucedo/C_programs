/* getarray() - gets a float and enters it into an array */
#include <stdio.h>
#include "def.h"

void getarray( float *array, FILE * infile)
{
    float input;
    char skip;
    int status, i;

    for(i=0; i < SIZE && !feof(infile) && (status = fscanf(infile, "%f", &input)) != EOF; i++)
    {

        if( status == FALSE )
        {
            if( fscanf(infile, "%c", &skip) == TRUE && skip == 'q' )
            {
                while(getchar() != '\n'); //clean up trailing characters
                break;
            }
        }
        else
        {
            (array[i] = input);
        }
    }
}
