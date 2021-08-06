/* filereverse.c - displays a file in reverse order */
#include<stdio.h>
#include<stdlib.h>
#define CTL_Z '\032' // eof marker in DOS

int main(int argc, char const *argv[]) {

  char ch;  //
  FILE *fp; //file pointer
  long count, last;

  if(argc != 2){ //program name[0] + first argument(fileneame)[1] = 2;
    puts("Usage: filereverse filename");
    exit(1);
  }
  if((fp=fopen(argv[1], "rb")) == NULL){
    printf("filereverse cannot open %s\n", argv[1]);
    exit(1);
  }

  fseek(fp, 0L, SEEK_END); //go to end of file
  last = ftell(fp);
  for(count = 1L; count <= '\r'; count++){
    fseek(fp, -count, SEEK_END);
      ch = getc(fp);
      if(ch != CTL_Z && ch != '\r')
        putchar(ch);
  }
  putchar('\n');
  fclose(fp);
  return 0;
}
