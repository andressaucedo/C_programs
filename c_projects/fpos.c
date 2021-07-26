#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define BUF 1024
#define NAME 32
int printfile( FILE *file, long start);
int printline( FILE *file, long start);
int filelength( FILE *file);

int main(void)
{
  char filename[NAME];
  FILE *file;
  long position = 1;
  int flength;
  char end;


  fputs("\nEnter a file to open: ",stdout);
  if(fscanf(stdin,"%s",filename) != 1){
    exit(1);
  }
  while(getchar() != '\n'); //clean up after fscanf in case of redundant input

  file = fopen(filename,"rb");
  if( file == NULL){
    fprintf(stderr, "Could not open file.\n");
    exit(2);
  }

  while(1){
      fputs("Enter a start position: ",stdout);
      if(fscanf(stdin,"%ld",&position) != 1){
        return 1;
      }
      while(getchar() != '\n'); //clean up after fscanf

      if(position > filelength(file)){
        fputs("File position exceeds file size, default set to 0\n",stdout);
        position = 0;
      }

      fputs("Print file or line?: ",stdout);
      if(fscanf(stdin,"%c",&end) != 1){
        return 1;
      }
      while(getchar() != '\n'); //clean up after fscanf
      fputc(end,stdout);
      if(end == 'f' || end == 'F'){
        fprintf(stdout,"%s from position %ld:\n",filename,position);
        printfile(file,position);
      }else if (end == 'l' || end == 'L'){
        fprintf(stdout,"%s from position %ld:\n",filename,position);
        printline(file,position);
      }else{
        fputs("Invalid option\n",stderr);
        continue;
      }
  }
return 0;
}

/*function that finds the length of the file in question*/
int filelength( FILE *file)
{
  int len;
  fseek(file,0L,SEEK_END);
  len = ftell(file);

  return len;
}

/*function that takes a file pointer and file position as a long and prints out
  lines from the file position to end of file through stdout*/
int printfile(FILE *file, long start)
{
  char buffer[BUF];

  fseek(file,start,SEEK_SET);

  setvbuf(file, buffer, _IONBF, BUF);
  while(fgets(buffer,sizeof(buffer),file) != NULL){
    fputs(buffer,stdout);
  }
  fputs("---------End of File----------\n",stdout);
return 0;
}

/*same as above function but prints out from file position to next newline*/
int printline(FILE *file, long start)
{
  char ch;
  fseek(file,start,SEEK_SET);

  ch=fgetc(file);
  while(ch != '\n'){
    fputc(ch,stdout);
    ch=fgetc(file);
  }
  putchar('\n');
return 0;
}
