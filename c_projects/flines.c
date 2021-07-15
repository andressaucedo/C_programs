/******************************************************************************
* flines.c - Takes two filenames as arguments and prints one line at a time   *
* from each until all the lines from the longer file are printed.             *
******************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define BUF 256
int lineprint(FILE *file);
int charprint(FILE *file);

int main(int argc, char const *argv[])
{
FILE *file[2];
int i;
  // BEGIN command line error checking
    if(argc != 3){
      fprintf(stderr, "usage: %s file1 file2\n", argv[0]);
      exit(1);
    }
    for(i=0;  i < (argc-1); i++){
      if( (file[i]=fopen(argv[i+1],"r")) == NULL){
        fprintf(stderr, "could not open %s\n", argv[i+1]);
        exit(2);
      }
    }
  // END command line error checking

  //loop continues until BOTH files reach their end
  while(1){
    if(feof(file[0]) && feof(file[1]))
      break;
    /* decomment and  replace this section for lineprint calls to use charprint
    charprint(file[0]);
    charprint(file[1]);
    putchar('\n');
    */
    lineprint(file[0]);
    lineprint(file[1]);
  }

  for(i=0;i<(argc-1);i++)
    fclose(file[i]);
  return 0;
}

/* lineprint function creates a buffer, gets a line and as long as the line
   is != NULL, will output it to stdout*/
int lineprint(FILE *file)
{
  char buffer[BUF];
  setvbuf(file,buffer,_IOLBF,BUF);
  if(fgets(buffer,BUF,file) != NULL)
    fputs(buffer,stdout);
  return 0;
}

/* charprint function prints each line together on the same line from the two
   files, otherwise the same as lineprint */
int charprint(FILE *file)
{
  char buffer[BUF];
  char ch;
  int i;
  setvbuf(file,buffer,_IOLBF,BUF);
  if(fgets(buffer,BUF,file) != NULL){
      for(i=0; buffer[i] != '\n'; i++){
        printf("%c",buffer[i]);
      }
  }
  return 0;
}
