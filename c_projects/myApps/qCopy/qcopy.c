/*****************************************************************************
 * qcopy.c - This program takes two arguments from the command line, the*
 * first is an existing file to be copied and the second is a file copy to be*
 * written out in binary mode or standard i/o.                               *
 *****************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define BUF 1024

int textcopy(FILE *infile, FILE *outfile);
int binarycopy(FILE *infile, FILE *outfile);

int main(int argc, char const *argv[])
{
  FILE *in;
  FILE *out;
    in = fopen(argv[1],"r");
    out = fopen(argv[2],"a");

  //BEGIN error checking block for command line call.
  if(argc != 3 && argc != 4){
    fprintf(stderr,
        "qcopy -- copies one file to a new file in either\n"
        "         text mode or binary mode by default.\n\n"
        "USAGE: %s sourcefile copyfile [-t TEXT MODE]\n\n",argv[0]);
    exit(1);
  }
  if(isalnum(*argv[2]) == 0){
    fputs("filenames must be alphanumeric characters.\n",stderr);
    exit(2);
  }
  if(in == NULL){
    fprintf(stderr,"unable to open file %s\n",argv[1]);
    exit(3);
  }
  if(argc > 3 && strcmp(argv[3],"-t") != 0){
    fputs("invalid option.\n",stderr);
    exit(4);
  }
  if(argc < 3){
    fputs("missing arguments.",stderr);
    exit(5);
  }
  if(argc > 4){
    fputs("too many arguments.",stderr);
    exit(6);
  }
  //END command line error checking*/

  if(argc < 4){
    binarycopy(in,out);
    fclose(in);
    fclose(out);
    return 0;
  } else if(strcmp(argv[3],"-t") == 0){
    textcopy(in,out);
    fclose(in);
    fclose(out);
    return 0;
  }
}

// function to copy infile to outfile using standard mode
int textcopy(FILE *infile, FILE *outfile)
{
  char buffer[BUF];
  setvbuf(infile,buffer,_IONBF,BUF);
  while(fgets(buffer,BUF,infile) != NULL){
    fputs(buffer,outfile);
  }
return 0;
}

// function to copy infile to outfile using binary mode
int binarycopy(FILE *infile, FILE *outfile)
{
  char buffer[BUF];
  setvbuf(infile,buffer,_IOFBF,BUF);
  while(1){
    if(feof(infile))
      break;
    fread(buffer,sizeof(char),1,infile);
    fwrite(buffer,sizeof(char),1,outfile);
  }
return 0;
}
