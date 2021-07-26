
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
  fprintf(stdout, "The word %s occurs %d times in file %s\n",word,wordcount,filename);

  return 0;
}

/*function to get a line and compare it to a word*/
int cmpline(char *word, FILE *file)
{
  int count=0;
  int i = 0;
  char buffer[BUFSIZE];
  long pos;
  long end;
  setvbuf(file,buffer,_IONBF,sizeof(buffer));
  fseek(file,0,SEEK_SET);
  pos = ftell(file);
  fseek(file,0,SEEK_END);
  end = ftell(file);
  rewind(file);

  while(i=0; i < end;i++){
    fseek(file,i,SEEK_SET);
    fgets(buffer,sizeof(word),file);
    if(strcmp(word,buffer) == 0){
      count++;
    }
  }

return count;
}
