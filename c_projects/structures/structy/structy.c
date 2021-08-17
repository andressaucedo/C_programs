/*  Program that shows how to declare structs using a header and pass struct
    pointers as arguments */

#include <stdio.h>
#include <string.h>
#include "st.h"
/*not sure if it's best practice to do so but by putting the struct type declaration in the st.h header file it keeps the code a bit cleaner, downside is that you may not be able to readily see what the struct fields are at a glance*/

void getmember(struct member *);

int main(void)
{
    struct member libby; //struct declaration

    getmember(&libby);

    fprintf(stdout,"\n%s\n%d\n%s\n",libby.name,libby.age,libby.email);

    return 0;
}

/* function that gets the input for the struct members using pointers */
void getmember(struct member * entry)
{

    fputs("Enter name:\n",stdout);
    fgets(entry->name, WRD, stdin);
    entry->name[strcspn(entry->name,"\n")] = '\0';

    fputs("Enter age:\n",stdout);
    fscanf(stdin,"%d",&entry->age); //fscan wants the '&' address operator
    while(getchar() != '\n'); //clean up trailing newline from fscanf

    fputs("Enter email:\n",stdout);
    fgets(entry->email, WRD, stdin);
    entry->email[strcspn(entry->email,"\n")] = '\0';
}
