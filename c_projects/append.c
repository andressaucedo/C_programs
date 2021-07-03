// append.c - program that appends file(s) to the end of a file
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFSIZE 1024
char temp[BUFSIZE];
void append(FILE *source, FILE *dest);

int main(int argc, char const *argv[]) {
  FILE *fa, *fr;
  int filenum;

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

  for(filenum = 1; filenum < argc -1; filenum++)
  {
      //produces error if one of the source file is same as destination
      if (strcmp(argv[argc-1], argv[filenum]) == 0)
        fputs("Cant append file to itself\n",stderr);
      //makes sure fr is not a NULL pointer/incorrect file name
      else if( (fr = fopen(argv[filenum], "r")) == NULL)
        fprintf(stderr, "Can't open %s\n", argv[filenum]);
      else
        {
            if (setvbuf(fr,NULL,_IOFBF,BUFSIZE) != 0)
            {
              fputs("Cant create output buffer\n",stderr);
              continue;
            }
            append(fr,fa);
            if(ferror(fr) !=0)
              fprintf(stderr, "Error in reading %s\n",argv[filenum]);
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
