/* append.c - program that appends source file(s) to the end of a file*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFSIZE 1024
#define STRSIZE 40
char temp[BUFSIZE];
void append(FILE *source, FILE *dest);
int filedef(char source[][STRSIZE], char *dest);

int main(int argc, char const *argv[]) {
  FILE *fa, *fr;
  int numfiles;
  int i;
  char source[5][STRSIZE];
  char dest[STRSIZE];
/*
  if(argc < 3)
  {
    fprintf(stderr, "Usage :%s source-file(s) destination-file\n",argv[0] );
    exit(1);
  }
*/
  numfiles = filedef(source,dest);

  if( (fa = fopen(dest, "a")) == NULL)
  {
    fprintf(stderr, "Can't open %s\n", dest );
    exit(2);
  }

  if(setvbuf(fa, NULL,_IOFBF,BUFSIZE) != 0)
  {
    fputs("Can't create output buffer\n",stderr);
    exit(3);
  }
fprintf(stdout,"%d\n",numfiles);
  for(i = 0; i < numfiles; i++)
  {
      //produces error if one of the source file is same as destination
      if (strcmp(dest, source[i]) == 0)
        fputs("Cant append file to itself\n",stderr);
      //makes sure fr is not a NULL pointer/incorrect file name
      else if( (fr = fopen(source[i], "r")) == NULL)
        fprintf(stderr, "Can't open %s\n", source[i]);
      else
        {
            if (setvbuf(fr,NULL,_IOFBF,BUFSIZE) != 0)
            {
              fputs("Cant create output buffer\n",stderr);
              continue;
            }
            append(fr,fa);
            if(ferror(fr) != 0)
              fprintf(stderr, "Error in reading %s\n",source[i]);
            if(ferror(fa) != 0)
              fprintf(stderr, "Error in writing %s\n",dest);
            fclose(fr);
        }
    }
      fclose(fa);
  return 0;
}

// function that writes to destination array
void append(FILE*source, FILE * dest)
{
  size_t bytes;
  extern char temp[]; // use the external temp array

  while ((bytes=fread(temp, sizeof(char),BUFSIZE,source)) > 0)
    fwrite(temp,sizeof(char),bytes,dest);
}

/*function that returns the number of filenames and defines names in a source
  filename 2d array as well as a singular destination character array*/
int filedef(char source[5][STRSIZE], char *dest)
{
  int numfiles;
  int strend;
  int i;

  fputs("Enter source file names:\n",stdout);
  for(numfiles=0;(fgets(source[numfiles],STRSIZE,stdin)) != NULL; numfiles++){
    if(source[numfiles][0] == '\n' || source[numfiles][0] == '\0'){
      break;
    }
  }

  /*loop to remove the trailing newline character left by fgets in source
    array*/
  for(i=0; i < numfiles; i++){
    strend = strcspn(source[i], "\n");
    source[i][strend] = '\0';
  }

  fputs("Enter destination file name:\n", stdout);
  fgets(dest,STRSIZE,stdin);
  /*another use of strcspn() to remove trailing newline from destination
    array*/
  strend = strcspn(dest,"\n");
  dest[strend] = '\0';

  return numfiles;
}
