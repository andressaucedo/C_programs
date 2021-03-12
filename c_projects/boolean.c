#include<stdio.h>
#include<stdbool.h>

int main(){
char b;
REWIND:
printf("Is Caleb fat?(y/n)\n");
scanf("%c", &b);
  if(b == 'y' || b == 'Y'){
    bool calebIsFat = true; // boolean logic
    printf("Caleb is fat.\n");
  }else if( b=='n'||b=='N'){
    bool calebIsFat = false;
    printf("Caleb is NOT fat.\n");
  }else{
    goto REWIND;
  }
return 0;
}
