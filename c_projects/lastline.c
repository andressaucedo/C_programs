/*****************************************************************************
* lastline.c - Takes at least one argument in the form of a readable file    *
* and returns the last few lines of the file to stdout. Optionally, will take* * a final argument in the form of an int to specify the number of lines to   * * return.                                                                    *
*                                                                            *
* example: ./lastline file1.txt file2.txt -6                                 *
******************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void show_end(char *name,long lines, FILE *file);

int main(int argc, char *argv[])
{
  FILE *fp;
  int file,i;
  long lines;
  char *foo; //endptr for strtol on line 25

  if(argc < 2)
  {
    fprintf(stderr,"Usage: %s file(s) [-n (n is number of lines)]\n", argv[0]);
    exit(1);
  }

  // i is a variable for number of arguments, subtracting one if the
  // last argument is an option
  if( (lines = strtol(argv[argc -1],&foo,10)) != 0){
    i=argc-1;
    if(lines < 0)
      lines *= -1;
  }else{
    i= argc;
    lines = 2;
  }

  for(file = 1; file < i; file++)
  {
      if((fp=fopen(argv[file],"r")) == NULL){
        fprintf(stderr,"%s can't open %s\n", argv[0], argv[file]);
        exit(2);
      }else{
        show_end(argv[file],lines,fp);
        fclose(fp);
      }
  }
  return 0;
}

void show_end(char *name, long lines, FILE *file)
{
    int ch;
    long newlines = 0;
    long count, start, last;

    printf("\n%s:\n", name);
    start = ftell(file);
    fseek(file, 0L, SEEK_END); //go to end of file
    last = ftell(file);
    for(count = 1L; count <= last; count++)
    {
      fseek(file, (-1*count), SEEK_END); //go backwards
      ch = getc(file);
      if(ch == '\n')
        newlines++; //count number of newlines
      if(newlines == lines + 1)
      {
          start=ftell(file);
          //or maybe ftell(file)-1;
          break;
      }
    }
    fseek(file,start, SEEK_SET);
    while ((ch = getc(file)) != EOF)
      putchar(ch);
}
