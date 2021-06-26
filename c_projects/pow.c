// pow.c - takes two arguments as base and exponent and prints
//calculation to stdout by default.
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
  if(argc != 3){
    fputs("Usage: pow base exponent\n", stderr);
    return 1;
  }
  char **pt;
  int exponent = atoi(argv[2]);
  double base = strtol(argv[1],pt,10);
  double total = base;
  int i = 0;

  for(i=1; i < exponent; i++)
    total *= base;

  fprintf(stdout,"%1.0lf\n", total);
  return 0;
}
