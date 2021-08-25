/* months.c - takes a command line argument 1-12 and will display the name of *
 *the month and the number of days it has. Uses a months.dat file to parse the*
 *information for the months. If you wanted to, you could make an alternate   * *file for leap years (hint,hint)                                             */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MO 12

struct cal {
    char name[12];
    char concise[3];
    int days;
    int num;
};
char *getend(int month, char * end);
void getmonth(struct cal *months, FILE *fp);

int main(int argc, const char *argv[])
{
    struct cal months[MO]; //our array of structs to hold all the months
    char ending[3]; //the postfixed string at the end of the month number 
    int i;
    unsigned int userArg = 1; //will be our scanned in command line argument
    FILE *fp; //file pointer for our database file

    //begin error check block
    if (argc != 2)
    {
        fprintf(stderr, "Missing/Too many arguments.\n"
                        "USAGE:\n"
                        "%s [MONTH NUMBER]\n"
                        "[MONTH NUMBER] - an integer 1-12\n", argv[0]);
        exit(1);
    }
    if (sscanf(argv[1], "%d", &userArg) != 1 || userArg > MO || userArg < 1)
    {
        fprintf(stderr, "Incompatible argument.\n"
                        "USAGE:\n"
                        "%s [MONTH NUMBER]\n"
                        "[MONTH NUMBER] - an integer 1-12\n", argv[0]);
        exit(2);
    }
    if((fp = fopen("months.dat","r")) == NULL){
        fputs("Missing months.dat file!\n",stderr);
        exit(3);
    }
    //end error check block
        
    for(i=0; i < MO; i++)
    {
        getmonth(&months[i],fp);
    }

    fprintf(stdout, "The %d%s month of the year is %s\n"
                    "and it has %d days.\n",
            userArg, getend(userArg, ending), months[userArg-1].name, months[userArg-1].days);

        return 0;
}

/*getmonth() yanks struct member info from a file named months.dat in the local directory*/
void getmonth(struct cal *months, FILE *fp)
{
    char line[sizeof(struct cal)];
    //fgets(months->name, sizeof(struct cal), fp);
    fscanf(fp,"%s %s %d %d", months->name, months->concise, &months->days, &months->num);
}

/* getend() finds the appropriate ending for month number*/
char *getend(int month, char * end)
{
    switch(month){
        case 1:
        end = "st";
        break;
        case 2:
        end = "nd";
        break;
        case 3:
        end = "rd";
        break;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        end = "th";
        break;
        
        default:
        end = "th";
        break;
    }
    return end;
}
