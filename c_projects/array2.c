#include<stdio.h>
int i, c;
int array[10];


for(i = 0 ; i < 10 ; ++i)
  array[i]=0;


int main()
{
while((c = getchar()) != EOF)
  for (i = 0 ; i <= 9 ; ++i){
    array[i]= i;}


  for (i = 0 ; i <= 9 ; ++i){
  printf("%i", array[i]);}


}
}
