#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define BUFSIZE 256

int main(int argc, char const *argv[]) {
  FILE *fp;
  int i;
  char linebuf[BUFSIZE];
  char ch = *argv[1];
  fp = fopen(argv[2],"r");

  //**This section is for error checking the command line input**
  if(argc != 3){
    fputs("Usage: charcheck char filename\n",stderr);
    exit(1);
  }
  if(isalnum(ch) == 0){
    fputs("First argument must be a character\n",stderr);
    exit(2);
  }
 if(fp == NULL){
    fprintf(stderr,"Failed to open file %s\n", argv[argc-1]);
    exit(3);
  }
  //**end error checking section**

  setvbuf(fp, linebuf,_IOLBF,sizeof(linebuf));
  while(fgets(linebuf,BUFSIZE,fp) != NULL){
    for(i=0; linebuf[i] != '\n'; i++){
      if(linebuf[i] == ch){
        fputs(linebuf,stdout);
        break;
      }
    }
  }

  fclose(fp);
  return 0;
}
