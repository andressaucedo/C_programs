#include<stdio.h>

/*count characters in input*/

main()
{
/*define variable as a doubleword*/
double nc;
/* Display a greeting and exit instructions*/
printf("###This program counts the characters you type\n###The ENTER key also counts towards the total character count\n###To exit press CTRL+D\n***************************************************************\n");
/*beginning of FOR loop*/
for (nc = 0; getchar() != EOF; ++nc)
    ;                           /*Null statement*/
    printf("%.0f\n", nc);       /*output contents*/
}
