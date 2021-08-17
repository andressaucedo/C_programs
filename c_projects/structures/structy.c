#include <stdio.h>
#include <string.h>
//#include "st.h"
#define WRD 40

struct member
{
    char name[WRD];
    int age;
    char email[WRD];
};

void getmember(struct member *);

int main(void)
{
    struct member libby;

    getmember(&libby);

    fputs(libby.name,stdout);
    fprintf(stdout,"%d",libby.age);
    fputs(libby.email,stdout);
    return 0;
}

/* exercise in using struct pointers and header files for the struct declaration */
void getmember(struct member * entry)
{

    fputs("Enter name:\n",stdout);
    fgets(entry->name, WRD, stdin);
    entry->name[strcspn(entry->name,"\n")] = '\0';

    fputs("Enter age:\n",stdout);
    fscanf(stdin,"%d",&entry->age);
    while(getchar() != '\n');

    fputs("Enter email:\n",stdout);
    fgets(entry->name, WRD, stdin);
    entry->name[strcspn(entry->name,'\n')] = '\0';
}
