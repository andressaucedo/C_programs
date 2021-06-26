/* wordstats.c - Takes input from either stdin or a file and tallies
/* different character types and spaces and outputs them to stdout.*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>
#define MAX 40
int getinput(FILE *infile, FILE *outfile);
int wordcount(FILE *filename);
void chartype(FILE *filename, int *digits, int *punct, int *lowercase, int *uppercase, int *space);

int main(int argc, char const *argv[]) {

char filearg[MAX];
int count = 0;
int chartotal, words;
int digits,punct,lowercase,uppercase, space;
    digits=punct=lowercase=uppercase=space=0;
FILE *infile;
FILE *outfile;

  if(argc > 1){
    infile = fopen(argv[1], "r");
      if(infile == NULL)
        fputs("Usage: wordstats [filename.txt] filename is optional",stderr);
        return 1;
  }else
  infile = stdin;
  outfile = fopen("wordstats.txt", "w+");
  puts("Enter input. Press Ctrl+D when done.");
  chartotal = getinput(infile,outfile);
  printf("\nTotal character count: %d\n",chartotal);
  rewind(outfile);
  words = wordcount(outfile);
  printf("Total word count: %d\n",words);
  rewind(outfile);
  chartype(outfile,&digits,&punct,&lowercase,&uppercase,&space);
  printf(
    "\n"
    "Digits: %d\n"
    "Punctuation: %d\n"
    "Lower case: %d\n"
    "Upper case: %d\n"
    "Blank space: %d\n",digits,punct,lowercase,uppercase,space);

  fclose(infile);
  fclose(outfile);
  return 0;
}

//gets input and returns the count of total characters
//getinput() also creates a file and writes input to it
int getinput(FILE *infile, FILE *outfile)
{
  int charcount = 0;
  char ch;

  while( (ch = fgetc(infile)) != EOF && feof(infile) == 0) {
    fputc(ch,outfile);
    charcount++;
  }
  return charcount;
}

// Counts the number of words defined as non-blank space collection
// of 1 or more characters.
int wordcount(FILE *filename)
{
  int chcount;
  int wordcount = 0; //word count
  int flag = 0; //flag == 0 means out of a word, 1 means in a word
  char ch;
  for(chcount = 0;(ch =fgetc(filename)) != EOF;chcount++){
    if(isspace(ch) == 0 && flag == 0){
      flag = 1; //beginning of a new word
    }else if(isspace(ch) == 0 && flag == 1){
      ; //middle of a word
    }else if( (isspace(ch) != 0 && flag == 1) || (ispunct(ch) != 0 && flag == 1) ){
      wordcount++;  //increment word counter
      flag = 0; //end of a word
      continue;
    }else
      ;
  }
  return wordcount;
}

//counts character types from file
void chartype(FILE *filename, int *digits, int *punct, int *lowercase, int *uppercase, int *space)
{
  char ch;

  while(1){
    ch=fgetc(filename);
    if( isdigit(ch) != 0)
      *digits += 1;
    else if( ispunct(ch) != 0)
      *punct += 1;
    else if( islower(ch) != 0)
      *lowercase += 1;
    else if ( isupper(ch) != 0)
      *uppercase += 1;
    else if (isspace(ch) != 0)
      *space += 1;
    if(feof(filename))
      break;
    }
}
