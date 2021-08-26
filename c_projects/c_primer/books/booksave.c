/*booksave.c- saves structs containing book entries to file using binary read/write and prints the data*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "books.h"

int yesno(void);
int getbooks(struct book *, int);
int printdat(struct book biblio[MAXBKS], FILE *pbooks);
int size = sizeof(struct book);

int main(void)
{
  struct book biblio[MAXBKS]; //array of structs
  int index,count; 
  int filecount; //the number of entries which relates to the biblio array
  FILE * pbooks;
  char filename[] = "books.dat";

  if((pbooks = fopen(filename,"a+b")) == NULL)
  {
    fprintf(stderr,"ERROR: Cant open file %s\n",filename);
    exit(1);
  }
  rewind(pbooks);

  filecount = printdat(biblio, pbooks); //reads number of books and prints
  count = filecount;

  if(count == MAXBKS)//if file cannot accept any more entries
  {
    fprintf(stderr,"%s file is full.\n",filename);
    exit(2);
  }

  count = getbooks(biblio,count); //gets new book entries, returns count
/*
  fputs("Here is a list of your books:\n",stdout);
  for(index = 0; index < count; index++)
  {
    fprintf(stdout,"%s  by:%s  $%.2f\n\n",biblio[index].title, biblio[index].author,biblio[index].price);
  }
*/
  /*The following lines append our structs to the file*/
  fseek(pbooks, 0L, SEEK_END);
  /*writing to our .dat file starting where we left off at the count of
    currently existing book entries(filecount)*/
  fwrite(&biblio[filecount], size, count - filecount,pbooks);
  int yn;
  
  do
  {
    fputs("View books.dat? Y/N: ", stdout);
  }while( (yn = yesno()) == 2);
  if(yn == 1) 
  {
    rewind(pbooks);
    printdat(biblio, pbooks);
  }else
  {
    puts("Goodbye.");
  }

  fclose(pbooks);
return 0;
}

