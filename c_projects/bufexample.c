#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define BUFSIZE 1024

int main(int argc, char const *argv[]) {
  int i;
  fprintf(stdout,"Let's get buff(ered)!\n");
  fprintf(stdout,"It's going to make us wait 5 seconds\nand then flush the buffer.\n");
  setvbuf(stdout,NULL,_IOFBF,BUFSIZE);
  for(i=1; i < 6;i++){
    sleep(1);
    fprintf(stdout,"%d\n",i);
    fflush(stdout);
  }
  fprintf(stdout,"Hey, it works!\n");
  fflush(stdout);

  return 0;
}
