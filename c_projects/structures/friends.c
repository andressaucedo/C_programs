/*friends.c -- program that illustrates pointers to structures using structs with information about friends*/
#include<stdio.h>
#define LEN 20

struct names {
  char first[LEN];
  char last[LEN];
};

struct guy {
  struct names handle;
  char favfood[LEN];
  char job[LEN];
  float income;
};

int main(void)
{
      static struct guy fellow[2] ={
          {{ "Egbert", "Snively"},
          "eggplant",
          "pipe cleaner",
          35000.69
          },
          {{"Rod", "Swillbelly"},
          "salmon mousse",
          "interior decorator",
          27000.00
        }
      };
    /*using pointers, we can iterate through an array of structures without having to use a loop*/
    struct guy * him; //This is the pointer to struct declaration
    printf("struct address #1: %p #2: %p\n", &fellow[0], &fellow[1]);
    him = &fellow[0]; //This is the pointer to struct definition
    printf("point to address #1: %p #2: %p\n", him, him +1);
    printf("him -> income is $%.2f:(*him).income is $%.2f\n", him->income, (*him).income);
    him++; //points to the next structure
    printf("him->favfood is %s  him->handle.last is %s\n",him->favfood, him->handle.last);

  return 0;
}
