/*****************************************************************\
* argrev.c - takes command line arguments and echoes them back in *
* reverse order.                                                  *
\*****************************************************************/
#include<stdio.h>

int main(int argc, char const *argv[]) {
  int i;

  for(i=argc-1; i < argc && i > 0; i--){
    fputs(argv[i],stdout);
    fputc(' ',stdout);
  }
  fputc('\n',stdout);
  return 0;
}
