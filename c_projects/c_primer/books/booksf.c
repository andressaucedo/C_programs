#include <stdio.h>
#include "books.h"
#include <string.h>

/* Function loop continues while we can read struct size chunks of data from our
file where the book entries are stored. */
int printBooks (struct book biblio[MAXBKS], FILE *pbooks)
{
    extern int size;
    extern char filename[];

    int count = 0;
    while (count < MAXBKS && fread(&biblio[count], size, 1, pbooks) == 1)
    {
        if (count == 0)
        {
            fprintf(stdout,"Current contents of %s:\n", filename);
        }
        printf("#%d - %s  by:%s  $%.2f\n\n",count, biblio[count].title, biblio[count].author, biblio[count].price);
        count++;
    }

    return count;
    }

int getBooks (struct book *biblio, int count)
{
    fputs("Please add Entries.\n"
          "[Enter] to stop: \n"
          "Book Title: ",
          stdout);

    while (count < MAXBKS && fgets(biblio[count].title, MAXWRD, stdin) != NULL && biblio[count].title[0] != '\0' && biblio[count].title[0] !=  '\n')
    {
        fputs("Author: ", stdout);
        fgets(biblio[count].author, MAXWRD, stdin);
        fputs("Price: ", stdout);
        fscanf(stdin, "%f", &biblio[count].price);
        while (getchar() != '\n')
         ; //clean up trailing chars from fscanf
        putchar('\n');
        count++;
        if (count < MAXBKS)
        {
            fputs("Book Title: ", stdout);
        }
    }
return count;
}

/*function to get a YES(1) or NO(0) or OTHER(2) answer */
int yesno(void)
{
    int num = 20;
    char yesno[num];
    char yn;
    fgets(yesno, num, stdin);
    sscanf(yesno, "%c", &yn);
    if (yn == 'y' || yn == 'Y')
    {
        return YES;
    }
    else if (yn == 'n' || yn == 'N')
    {
        return NO;
    }else
        return OTHER;
}

//string sorting function using pointers
void stringsort(struct book *biblio, int strCount)
{
    char temp[MAXWRD];
    int top, seek;
    /*if strcmp(top,seek) returns a positive integer it means that top comes after seek in the machine collating sequence (ASCII) so we swap the two values in the pointer array */
    for (top = 0; top < strCount - 1; top++)
        for (seek = top + 1; seek < strCount; seek++)
            if (strcmp(biblio[top].title, biblio[seek].title) > 0)
            {
                strcpy(temp, biblio[top].title);
                strcpy(biblio[top].title, biblio[seek].title);
                strcpy(biblio[seek].title, temp);
            }
}