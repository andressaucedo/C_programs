/*booksave.c- saves structs containing book entries to file using binary read/write and prints the data*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "books.h"

int yesno(void);
int getBooks(struct book *, int);
int printBooks(struct book biblio[MAXBKS], FILE *pbooks);
void stringsort(struct book *biblio, int strCount);
int size = sizeof(struct book);
char filename[] = "books.dat";

int main(void)
{
  struct book biblio[MAXBKS]; //array of structs
  int index,count; 
  int filePosition; //the number of entries which relates to the biblio array
  FILE * pbooks;

  if((pbooks = fopen(filename,"r+b")) == NULL)
  {
    fprintf(stderr,"ERROR: Cant open file %s\n",filename);
    exit(1);
  }
  rewind(pbooks);

  filePosition = printBooks(biblio, pbooks); // Returns number of entries and prints the output of the file
  count = filePosition;

  if(count == MAXBKS)//if file cannot accept any more entries
  {
    fprintf(stderr,"%s file is full.\n",filename);
    exit(2);
  }

  count = getBooks(biblio,count); //gets new book entries, returns count

  /* The following lines append our structs to the file
  writing to our .dat file starting where we left off at the count of
  currently existing book entries(filePosition). */
  fseek(pbooks, 0L, SEEK_END);
  fwrite(&biblio[filePosition], size, count - filePosition,pbooks);
  int yn;  //yn takes the return of yesno() - yes=1, no=0, other=2
  
  do
  {
    fprintf(stdout,"View %s? Y/N: ", filename);
  }while( (yn = yesno()) == OTHER);
  if(yn == YES) 
  {
    rewind(pbooks);
    printBooks(biblio, pbooks);
  }else 
  {
    puts("Goodbye.");
  }
  /****************************************************************************/
  
  puts("ordering array, writing to file\n");
  stringsort(biblio,count);
  rewind(pbooks);
  fwrite(&biblio[0],size,count,pbooks);
  rewind(pbooks);
  printBooks(biblio,pbooks);
  fclose(pbooks);
return 0;
}

