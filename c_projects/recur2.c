#include<stdio.h>
int recurser(int i);

int main(void)
{
  recurser(1);
return 0;
}

int recurser(int i)
{

  printf("%d", i);
  if(i<10){
    recurser(i+1);
  }
  printf("%d", i);

return 0;
}
