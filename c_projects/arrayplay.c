#include<stdio.h>
#define MAX 15              //set max word length for index
#define OUT 0
#define IN 1

//prints an array showing how many characters/word up to 15 max characters
main()
{
int c, i, cnt, ovr, state;
int array[MAX];
state = OUT;
c = i = cnt = ovr = 0;            //set values to 0
for (i=0; i < MAX; i++)
  array[i] = 0;

  while ((c=getchar()) != EOF)
{
      if ( c == ' ' || c == '\n' || c == '\t')
          if (state=IN)
              ++array[cnt];
              state = OUT;
              cnt = 0;
           if (state=OUT)
              cnt = 0;
      else
        if (cnt < MAX && cnt >= 0)
        state = IN;
        cnt++;
        ++array[cnt];
       if(cnt > MAX || cnt < 0)
        ++ovr;



}
for(i = 0; i < MAX; i++)
    printf(" %d", array[i]);
    putchar('\n');
    printf(" %d overflow characters: ", ovr);
    putchar('\n');
}
