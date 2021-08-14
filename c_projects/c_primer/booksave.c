
/*booksave.c- saves structs to file using binary read/write*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "books.h"

int main(void)
{
  struct book biblio[MAXBKS]; //arrrya of structs
  int count = 0;
  int index, filecount;
  int size = sizeof(struct book);
  FILE * pbooks;
  char filename[] = "books.dat";

  if((pbooks = fopen(filename,"a+b")) == NULL)
  {
    fprintf(stderr,"ERROR: Cant open file %s\n",filename);
    exit(1);
  }
  rewind(pbooks);

  /*loop continues while we can read struct size chunks of data from our
    file where the book entries are stored*/
  while(count < MAXBKS && fread(&biblio[count], size, 1, pbooks) == 1)
  {
    if(count == 0){
      fputs("Current contents of book.dat:\n",stdout);
    }
    printf("%s by %s :$%.2f\n", biblio[count].title, biblio[count].author, biblio[count].price);
    count++;
  }
  /*the filecount is the number of book entries that exist already*/
  filecount = count;

  if(count == MAXBKS)
  {
    fprintf(stderr,"%s file is full.\n",filename);
    exit(2);
  }

  fputs("Please add new book title.\n"
        "[Enter] to stop: ", stdout);

  while(count < MAXBKS && fgets(biblio[count].title, sizeof(biblio[count].title),stdin) != NULL && biblio[count].title[0] != '\0' && biblio[count].title[0] != '\n')
  {
    fputs("Author: ",stdout);
    fgets(biblio[count].author,sizeof(biblio[count].author),stdin);
    fputs("Price: ",stdout);
    fscanf(stdin, "%f",&biblio[count].price);
    while(getchar() != '\n'); //clean up trailing chars from fscanf
    count++;
    if(count < MAXBKS)
    {
      fputs("Book Title: ",stdout);
    }
  }

  fputs("Here is a list of your books:\n",stdout);
  for(index = 0; index < count; index++)
  {
    fprintf(stdout,"%s by %s: $%.2f\n",biblio[index].title, biblio[index].author,biblio[index].price);
  }

  /*The following lines append our structs to the file*/
    fseek(pbooks, 0L, SEEK_END);
    /*writing to our .dat file starting where we left off at the count of
      currently existing book entries(filecount)*/
    fwrite(&biblio[filecount], size, count - filecount,pbooks);
    fclose(pbooks);

return 0;
}
