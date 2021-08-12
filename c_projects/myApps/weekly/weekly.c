#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#include<string.h>
#define WRD 40
#define WEEK 7
#define STARS "\n*********************************************\n"


char* gettime();            //gets local time
float transact(void);  //gets daily totals and name labels
float percent(float num, float *per);    //calculates percentages

int main(int argc, char const *argv[])
{
    int i;
    float per;
    char label[WRD];
    float days[WEEK];
    float wktotal, daytotal, x, z;
    FILE * file;

    if(argc < 2 || argc > 2)
    {
        fprintf(stderr, "weekly -- totals weekly income and percentages\n"
            "USAGE:\n"
            "%s [FILENAME]\n"
            "[FILENAME] - is the name of file to record output of program."
            "\n",argv[0]);
            exit(1);
    }
    if((file = fopen(argv[1],"a+")) == NULL)
    {
        fprintf(stderr, "Cannot open file %s\n", argv[1]);
        exit(2);
    }
    fprintf(file,"%s",STARS); //file entry separator
    fprintf(file,"%s\n",gettime()); //timestamp file entry

    /*loop runs transact() and finds the daily and weekly total*/
    for(i = 0, wktotal = 0; i < WEEK && label[0] != '\n'; i++)
    {
        daytotal = 0;

        fputs("Type date/label or ENTER to end:\n",stdout);
        fgets(label,sizeof(label), stdin);
        if(label == NULL || strcmp(label,"\n\0") == 0)
        {
            break;
        }
        fprintf(file,"%s", label);

        while( (x = transact()) != 0)
        {
            fprintf(file,"\t%.2f:\n", x);
            daytotal += x;
        }

        days[i] = daytotal;
        wktotal += daytotal;
    }
    fprintf(stdout,"Total all days is: $%.2f\n\n", wktotal);
    fprintf(file,"\t--------\n"
                 "\t%.2f total\n", wktotal);

    z = percent(wktotal,&per);
    printf("\t%d%% of $%.2f = $%.2f\n"
    "\tThe remaining %d%% = $%.2f"
    "\n",(int)(per * 100),wktotal, z,(int)(100 -(per * 100)), (wktotal - z));
    fprintf(file,"\t--------\n"
    "\t%d%% of $%.2f = $%.2f\n"
    "\tThe remaining %d%% = $%.2f"
    "\n",(int)(per * 100),wktotal, z,(int)(100 -(per * 100)), (wktotal - z));

return 0;
}

// function that records a transaction and returns the amount;
float transact(void)
{
    float result;
    float entry;
    char trans[WRD];
    int x;

    fputs("Trans. amount: $",stdout);
    fgets(trans,sizeof(trans), stdin);

    x =sscanf(trans,"%f",&entry);

    if(x == 1)
    {
        result = entry;
    }
    else if(x < 1)
    {
        result = 0;
    }

return result;
}

char* gettime()
{
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char myTime[64];
    char *time;
    assert(strftime(myTime, sizeof(myTime), "%c", tm));
    time = myTime;
return time;
}

/*finds a percentage for the wktotal and returns the calculation*/
float percent(float num, float *per)
{
    float calc;
    char input[WRD];
    char choice;
    do{
        puts("Do you wish to find a percentage");
        fgets(input,sizeof(input),stdin);
        sscanf(input,"%c", &choice);
        if(choice == 'y' || choice == 'Y')
        {
            fputs("Enter percentage to calculate:\n",stdout);
            while(scanf("%f",per) != 1){
                fputs("Invalid number, enter an integer 1-100:\n",stdout);
            }

            calc = (*per /= 100) * num;

        }
        else if(choice == 'n' || choice == 'N')
        {
            *per = 1;
            return num;
        }
        else
        {
            choice = '\0';
        }
    }while(choice == '\0');

return calc;
}
