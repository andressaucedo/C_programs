/* addaword.c - program using fprintf(), fscanf() and rewind() */
#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int countlines( FILE *file);

int main(void)
{
  FILE *fp;
  char ch;
  char words[MAX];
  char string[512];
  int count = 0;

  if((fp = fopen("words.txt","a+")) == NULL)
  {
    fprintf(stderr, "can't open \"words.txt\" file.\n");
    exit(1);
  }
  puts("Enter words to add to the file; press the Enter "
        "key at the beginning of a line to terminate.");

  rewind(fp);
  while(fgets(string,sizeof(string),fp) != NULL)
    count++;
    if(string[0] == '\n')
      count--;
  while(fgets(words,sizeof(words),stdin) != NULL && words[0] != '\n'){
    count++;
    fprintf(fp,"%d %s",count,words);
  }
    //print out contents of file
    puts("File contents:");
    rewind(fp); //go back to the beginning of file
    while(fscanf(fp,"%d %s",&count,words) == 2)
      printf("%d %s\n",count,words);
    if(fclose(fp) != 0)
      fprintf(stderr,"Error closing file.");
  return 0;
}

int countlines(FILE *file){

  return 1;
}
