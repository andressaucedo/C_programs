/*****************************************************************************
 * findchar.c - This program is meant to take the first argument as a char   *
 * and all following arguments are files to be searched. If no files are     *
 * specified, the program will take input from stdin by default. The output  *
 * is the number of times the character is found in each file, sent to       *
 * stdout.                                                                   *
 *****************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define BUF 1024

int search(char object, FILE *subject);

int main(int argc, char const *argv[])
{
  int i,count;
  FILE *fp;

    //BEGIN error check for command line call
      if(argc < 2){
        fprintf(stderr,"usage %s [character] [files to search]", argv[0]);
         exit(1);
      }
    //END error check for command line call

    //if no files are specified
    if(argc == 2){
      puts("No input file, please enter input to search (Ctrl+D to end):");
      count = search(argv[1][0],stdin);
      fprintf(stdout,"%s: %d\n","from input",count);
    }

    //otherwise use files for input
    else{
      for(i=2; i < argc; i++){
          fp = fopen(argv[i],"r");
          count = search(argv[1][0],fp);
          fprintf(stdout,"%s: %d\n",argv[i],count);
      }
      fclose(fp);
    }
return 0;
}

int search(char object, FILE *subject)
{
    long start,end;
    int count = 0;
    char ch;

    while((ch=getc(subject)) != EOF){
      if( ch == object)
        count++;
    }

return count;
}
