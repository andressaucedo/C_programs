#include<stdio.h>
#define IN 1        /*inside a word*/
#define OUT 0       /*outside a word*/



int main()
{
int c, i, nc, state;
int graph[10];


LOOP do:
c = i = nc = 0;
state = OUT;

while ((c = getchar()) != EOF)
  {
  ++nc;
  if (c == ' ' || c == '\n' || c == '\t')
    {
    state = OUT;
    --nc;
    }
else if (state == OUT)
    {
    state = IN;
    }
  if (state = IN)
    {
    printf("%d\n",++graph[nc] );
    }
goto LOOP
;
  }

}
