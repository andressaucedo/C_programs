/* lineitems.c -- takes in line items and their prices and prints them to a
                  file specified by . */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#include<string.h>

#define MAX 256
#define CMNT 80

struct items
{
    float price;
    char label[CMNT];
}list[MAX];

float getprice(void);
void getcomment(char *label);
char* gettime();

int main(int argc, char const *argv[])
{
    FILE *listfile;
    char help[] = "--help";
    int i;
    float sum;

    //command line call checking block
    if(argc > 2 || argc < 2){
        fprintf(stderr, "USAGE:\n"
                "   %s [FILENAME] [--help]\n",argv[0]);
        exit(1);
    }
    if( strcmp(argv[1],help) == 0){
        fprintf(stdout, "lineitems -- a program to record line items, their "
                        "prices and to print the output to a designated file."
                        "Input takes up to two numbers and allow for "
                        "operations using polish notation.\n"
                        "USAGE:\n"
                        "%s [FILENAME] [--help]\n\n"
                        "[FILENAME] - user specified filename to be created \n"
                        "             or ammended to for the list items and\n"
                        "              calculations.\n\n"
                        "[--help] - display this help menu.\n",argv[0]);



        return 1;
    }
    listfile = fopen(argv[1], "a+");
    fprintf(listfile, "%s\n", gettime()); //prints time to file

/* this loop gets the input, puts it in a struct and also prints it to file */
    for(i = 0, sum = 0; (list[i].price = getprice()) != '\0' && i < MAX;i++){
        getcomment(list[i].label);
        sum += list[i].price;
        fprintf(listfile, "%.2f - %s\n", list[i].price,list[i].label);
    }
    fprintf(stdout,"Item total: %.2f\n",sum);
    fprintf(listfile,"Item total: %.2f\n",sum);

    return 0;
}

/* function to get the price and perform any math on the item prior to writing it in to memory */
float getprice(void)
{
    float num1;
    float num2;
    float result = 0;
    int x;
    char op;
    char line[128];

    fputs("Enter the price for the item: ",stdout);
    fgets(line,sizeof(line),stdin);
    x = sscanf(line,"%f %f %c",&num1,&num2,&op);
    if(x < 1){
        result = 0;
    }

    else if(x < 3 && x >= 1){
        result = num1;
    }
    else if (x == 3)
    {
            switch(op){
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                result = num1 / num2;
                break;
            default:
                result = num1 * num2;
                break;
        }
    }

return result;
}

/* function to add a label or comment to items */
void getcomment(char *label)
{
    fputs("Enter label or comment, Enter to skip:\n", stdout);
    fgets(label,CMNT,stdin);
}

/* function gets local time */
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
