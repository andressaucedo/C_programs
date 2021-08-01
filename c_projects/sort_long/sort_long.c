#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "def.h"
extern void sort(float array[]);
extern void getarray(float array[], FILE * infile);
extern void printarray(float array[]);


int main(int argc, char const *argv[])
{
    float array[SIZE];
    FILE *fp;

    if (argc < 2)
    {
        fputs("Enter a maximum of 100 numbers, enter 'q' to stop:\n",stdout);
        getarray(array,stdin);
    }
    if (argc > 2)
    {
        fputs("Too many arguments\n",stderr);
        exit(1);
    }
    if ( strcmp(argv[1],"--help") == 0 )
    {
        fputs(
            "sort_long - a program to sort long numbers\n"
            "USAGE: sort_long [OPTIONS] [FILE]\n"
            "   --help - launch this menu\n"
            "   [FILE] - an input file (default is stdin)\n",stderr);
        exit(2);
    }

    if (argc == 2 && strcmp(argv[1],"--help") != 0){

         if ( (fp = fopen(argv[1],"r")) == NULL)
         {
             fprintf(stderr, "Error: Could not open %s\n", argv[1]);
             exit(1);
         }

         else
         {
             getarray(array,fp);
         }

    }

    //sort(array);
    //printarray(array);
fclose(fp);
return 0;
}
