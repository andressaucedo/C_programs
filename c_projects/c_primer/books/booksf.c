#include <stdio.h>
#include "books.h"
/*
int sortbooks(struct book *in, FILE *fp)
{
    struct book alpha;
    rewind(fp);
    

}

/*function loop continues while we can read struct size chunks of data from our
file where the book entries are stored*/
int printdat(struct book biblio[MAXBKS], FILE *pbooks)
{
    extern int size;
    int count = 0;
    while (count < MAXBKS && fread(&biblio[count], size, 1, pbooks) == 1)
    {
        if (count == 0)
        {
            fputs("Current contents of book.dat:\n", stdout);
        }
        printf("%s  by:%s  $%.2f\n\n", biblio[count].title, biblio[count].author, biblio[count].price);
        count++;
    }

    return count;
    }

int getbooks(struct book *biblio, int count)
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
        return 1;
    }
    else if (yn == 'n' || yn == 'N')
    {
        return 0;
    }else
        return 2;
}