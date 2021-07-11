/*lastline.c - prints last lines of files */
#include<stdio.h>
#include<stdlib.h>
void show_end(char *name, FILE *file);

int main(int argc, char *argv[])
{
  FILE *fp;
  int file;

  if(argc < 2)
  {
    fprintf(stderr,"Usage: %s file(s)\n", argv[0]);
    exit(1);
  }
  for(file = 1; file < argc; file++)
  {
      if((fp=fopen(argv[file],"r")) == NULL){
        fprintf(stderr,"%s can't open %s\n", argv[0], argv[file]);
        exit(2);
      }else{
        show_end(argv[file],fp);
        fclose(fp);
      }
  }
  return 0;
}

void show_end(char *name, FILE *file)
{
    int ch;
    int newlines = 0;
    long count, start, last;

    printf("%s:\n", name);
    start = ftell(file); //go to end of file
    fseek(file, 0L, SEEK_END); //go backward
    last = ftell(file);
    for(count = 1L; count <= last; count++)
    {
      ch = getc(file);
      if(ch == '\n')
      newlines++;
      if(newlines == 2)
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
