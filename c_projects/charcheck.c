#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define BUFSIZE 256

int main(int argc, char const *argv[]) {
  FILE *textfile;
  int i;
  int flag = 0;
  char linebuf[BUFSIZE];
  char ch;
  textfile = fopen(argv[1],"r");
  //**This section is for error checking the command line input**
  if(argc != 3){
    fputs("Usage: charcheck char filename\n",stderr);
    exit(1);
  }
  /*if(isalnum((ch=*argv[1]) == 0)){
    fputs("First argument must be a character\n",stderr);
    exit(2);
  }
/*  if(textfile != NULL){
    fprintf(stderr,"Failed to open file %s\n", argv[argc-1]);
    exit(3);
  }*/
  //**end error checking section**
//  setvbuf(textfile, linebuf,_IOFBF,BUFSIZE);
  fgets(linebuf,BUFSIZE,textfile);

  for(i=0; linebuf[i] != '\n'; i++)
    if(linebuf[i] == ch)
      fputs(linebuf,stdout);
      fflush(stdout);

  fclose(textfile);
  return 0;
}
