#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NUM 5
#define MAX 40

long testfunc(char *array);
void getinput(char array[][MAX]);
int main()
{
  char input[NUM];
  char array[NUM][MAX];
  long answer = testfunc(input);
  int i;

 printf("%ld\n", answer);

 getinput(array);
 for( i=0; i < NUM; i++)
   fputs(array[i],stdout);

return 0;
}

long testfunc(char *array)
{
char *ptr;
long converted;
fgets(array, sizeof array, stdin);
converted = strtol(array,&ptr,10);
return converted;
}

void getinput(char array[][MAX])
{
  int i;
  for( i=0; i < NUM; i++)
    fgets(array[i],MAX,stdin);

}
