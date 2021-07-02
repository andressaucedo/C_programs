// append.c - program that appends file(s) to the end of a file
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFSIZE 1024
char temp[BUFSIZE];
void append(FILE *source, FILE *dest);

int main(int argc, char const *argv[]) {
  FILE *fa, *fr;
  int file;

  if(argc < 3)
  {
    fprintf(stderr, "Usage :%s source-file(s) destination-file\n",argv[0] );
    exit(1);
  }

  if( (fa = fopen(argv[argc-1], "a")) == NULL)
  {
    fprintf(stderr, "Can't open %s\n", argv[argc-1] );
    exit(2);
  }

  if(setvbuf(fa, NULL,_IOFBF,BUFSIZE) != 0)
  {
    fputs("Can't create output buffer\n",stderr);
    exit(3);
  }

  for(file = 1; file < argc -1; file++)
  {
      if (strcmp(argv[argc-1], argv[file]) == 0)
        fputs("Cant append file to itself\n",stderr);
      else if( (fr = fopen(argv[file], "r")) == NULL)
        fprintf(stderr, "Can't open %s\n", argv[file]);
      else
        {
            if (setvbuf(fr,NULL,_IOFBF,BUFSIZE) != 0)
            {
              fputs("Cant create output buffer\n",stderr);
              continue;
            }
            append(fr,fa);
            if(ferror(fr) !=0)
              fprintf(stderr, "Error in reading %s\n",argv[file]);
            if(ferror(fa) != 0)
              fprintf(stderr, "Error in writing %s\n",argv[argc-1]);
            fclose(fr);
        }
    }
      fclose(fa);
  return 0;
}

void append(FILE*source, FILE * dest)
{
  size_t bytes;
  extern char temp[]; // use the external temp array

  while ((bytes=fread(temp, sizeof(char),BUFSIZE,source)) > 0)
    fwrite(temp,sizeof(char),bytes,dest);
}
