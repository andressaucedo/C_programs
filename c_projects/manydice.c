#include<stdio.h>
#include<stdlib.h>
extern void srand1(unsigned);
extern int rollem(int);

int main(int argc, char const *argv[])
{
  int dice,count,roll;
  short seed;
  int sides;

  fprintf(stdout,"Enter a seed value\n");
  fscanf(stdin,"%hd",&seed);
  srand1(seed);
  fprintf(stdout,"Enter the number of sides per die, 0 to quit:\n");
  while(fscanf(stdin,"%d",&sides) == 1 && sides > 0){
    fprintf(stdout,"How many dice?\n");
    fscanf(stdin,"%d",&dice);
    for(roll = 0, count = 0; count < dice; count++){
      roll += rollem(sides);
    }
    fprintf(stdout,"You have rolled a %d using %d %d-sided dice.\n",roll,dice,sides);
    fprintf(stdout,"Enter the number of sides per die, 0 to quit:\n");
  }
  fprintf(stdout,"GOOD FORTUNE TO YOU!\n");
  return 0;
}
