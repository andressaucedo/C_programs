/*******************************************************************\
 * stepten.c - This program is used to help keep track of a person's*
 * daily inventory during recovery by prompting the user with       *
 * questions and saving the answers with date in a text file log.   *
 \******************************************************************/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 40
#define LENGTH 1000
#define LINE "*****************************************************\n"

int greeting(void);
int getdate(FILE *log, char *date);
int questions(FILE *log);

int main(int argc, char const *argv[]) {
  FILE *log;
  char date[MAX];
  log = fopen("stepten.txt","a+");

  greeting();
  getdate(log,date);
  questions(log);
  fputs(LINE,log);

  fclose(log);
return 0;
}

int greeting(void)
{
  printf(
    "**************************************************************\n"
    "*                                                            *\n"
    "*                   Step 10 Daily Inventory                  *\n"
    "*                                                            *\n"
    "**************************************************************\n"
    "\n");

  return 0;
}

int getdate(FILE *log, char *date)
{
  puts("Enter the date:");
  fgets(date, MAX, stdin);
  fputs("Enter the date:\n", log);
  fputs(date,log);
return 0;
}

int questions(FILE *log)
{
  int i;
  char answer[LENGTH];
  char question[][256]={
    {"Was I resentful?\n"},
    {"Was I dishonest?\n"},
    {"Did I promptly admit when I was wrong today?\n"},
    {"Do I owe an apology?\n"},
    {"Did I do or say something today out of fear?\n"},
    {"Have I kept something to myself which should be discussed with another person at once?\n"},
    {"Did I think today of what I could do for others?\n"}
  };

  for(i=0;i < 7; i++){
    fputs(question[i],stdout);
    fgets(answer,LENGTH,stdin);
    fputs(question[i],log);
    fputs(answer,log);
    fputs("\n",log);
  }
return 0;
}
