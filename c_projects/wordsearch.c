/* wordsearch.c - program that takes as command line arguments a string and a  filename for a file to search. The program returns the number of times the word appears in the file to stdout */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define WORDSIZE 40
#define BUFSIZE 1024
int cmpline(char *word, FILE *file);

int main(int argc, char const *argv[])
{
  int wordcount;
  char word[WORDSIZE];
  char filename[WORDSIZE];
  FILE *file;
  file = fopen(argv[2],"rb");
  strcpy(word,argv[1]);
  strcpy(filename,argv[2]);

  if(argc < 3){
    fprintf(stderr, "usage: wordsearch word filename\n");
    exit(1);
  }
  if(file == NULL){
    fprintf(stderr, "could not open file %s\n", filename);
    exit(2);
  }

  wordcount = cmpline(word,file);
  fprintf(stdout, "The word \"%s\" occurs %d times in file %s\n",word,wordcount,filename);
  fclose(file);
  return 0;
}

/*function to get a line and compare it to a word*/
int cmpline(char *word, FILE *file)
{
  int count=0;
  int length;
  long i;
  char buffer[BUFSIZE];
  long end;

  //get length of word +1 for '\0'
  length = strlen(word) + 1;

  setvbuf(file,buffer,_IONBF,length);
  fseek(file,0,SEEK_END);
  end = ftell(file);
  rewind(file);

  for(i = 0; i < end; i++){
    fseek(file,i,SEEK_SET);
    fgets(buffer,length,file);
    if(strcmp(word,buffer) == 0){
      count++;
    }
  }

return count;
}
