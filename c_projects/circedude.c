#include<stdio.h>
#include<unistd.h>

int main(void)
{
  printf(
    "__________\n"
    "|  O   O  |\n"
    "|    U    |\n"
    "|  _____  |\n"
    "|_________|\n");
    int i;
    for(i=1; i < 4; i++){
      sleep(1);
      printf("    %d\n",i);
    }
    sleep(1);
    puts("Hello Circe!!!");

return 0;
}
