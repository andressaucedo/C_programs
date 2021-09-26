#include <stdio.h>
#include <string.h>
#include "practice.h"
int yesno(FILE *fp);

int main(void)
{
    struct quotes stoic;
    struct quotes input;
    int yn;
    FILE * my_file = fopen("famous_sayings.txt","a+");
    

    fputs("Do you want to append a new entry to file?:\n",stdout);
    yn = yesno(stdin);   
    if(yn == 1)
    {
        fputs("Enter a famous saying: \n", stdout);
        fgets(stoic.saying, sizeof(stoic.saying), stdin);
        fputs("Enter the name of the author: \n", stdout);
        fgets(stoic.author, sizeof(stoic.author), stdin);
        fwrite(&stoic, sizeof(struct quotes), 1, my_file);
    }
    
    fputs("Do you wish to print file?: ",stdout);
    yn = yesno(stdin);
    if(yn == 1)
    {
        rewind(my_file);
        while (fread(&input, sizeof(struct quotes), 1, my_file))
        {
            fprintf(stdout, "\"%s\"\t-%s\n", input.saying, input.author);
        }
    }
        
    fclose(my_file);

    return 0;
}

int yesno(FILE * fp)
{
    char response[20];
    char yes_no;
    fgets(response, sizeof(response), fp);
    sscanf(response, "%c", &yes_no);

    if (yes_no == 'y' || yes_no == 'Y')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}