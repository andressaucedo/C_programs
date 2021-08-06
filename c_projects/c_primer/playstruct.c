#include<stdio.h>

int main(void) {
    struct date{
        int day;
        int year;
        char month[20];
    }test;

    //struct date test;

    puts("Enter the day:");
    fscanf(stdin,"%d",&test.day);

    puts("Enter the month:");
    fscanf(stdin,"%s",test.month);

    puts("Enter the year:");
    fscanf(stdin,"%d",&test.year);

    fprintf(stdout, "\nThe date today is %s %d, %d.\n", test.month, test.day, test.year);

    return 0;
}
