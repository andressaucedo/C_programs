/* bufexample.c - This program illustrates the different ways we can initialize
and use setvbuf() to make our own buffer using a file pointer (in this case
simply stdout), a constant for the size of the buffer and either full buffering
or line buffering modes/. Decommenting any of the lines with setvbuf() allows
us to see how they can all accomplish the simple task of displaying a countdown
and flushing the buffer.*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#define BUFSIZE 1024

int main(int argc, char const *argv[]) {
  int i;
  FILE *fp;
  char mybuf[BUFSIZE];
  char string[BUFSIZE];
  fp = fopen("tester.txt","r");
  fprintf(stdout,"Let's get buff(ered)!\n");
  fprintf(stdout,"It's going to make us wait 5 seconds\n"
  "and then flush the buffer.\n");
  /*The commented out version of setvbuf() below automatically makes a buffer
  using the NULL pointer argument and makes it sizeof BUFSIZE*/
  //setvbuf(stdout,NULL,_IOFBF,BUFSIZE);

  /*The following version is line buffered and doesn't require a predefined
  buffer array or the fflush() function as it flushes every time a newline is
  encountered*/
  //setvbuf(stdout,NULL,_IOLBF,BUFSIZE);

  //The current version being used makes use of our predefined buffer array
  setvbuf(fp,mybuf,_IOFBF,sizeof mybuf);
  for(i=1; i < 6;i++){
    sleep(1);
    fprintf(stdout,"%d\n",i);
    fflush(stdout);
  }
  fprintf(stdout,"Hey, it works!\n");

  while(1){
    fgets(string,BUFSIZE,fp);
    fputs(string,stdout);
    if(feof(fp))
      break;
  }

fflush(NULL);
fclose(fp);
  return 0;
}
