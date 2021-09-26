#include <stdio.h>
#include <string.h>
#define INSTR 20
#define BSTR 36

int main(void)
{
  char inputString[INSTR];
  char binaryString[BSTR];
  unsigned int inputDecimal;
  unsigned int binaryNum;
  int i;
  int j;

  fputs("Welcome to newbin binary number generator.\n"
        "To end program type 'quit'.\n\n", stdout);
  while(1)
  {
    fputs("Enter a number: ", stdout);
    fgets(inputString, sizeof(inputString), stdin);
    if(strcmp(inputString,"quit\n") == 0)
    {
      break;
    }
    if(sscanf(inputString, "%d", &inputDecimal) != 1)
    {
      fputs("Error: invalid input. Enter a number.\n\n",stdout);
      continue;
    }

    for(i = 0; i < BSTR; i++)
    {
      binaryString[i] = '\0';
    }

    for(binaryNum = 1, i=0;binaryNum << 1 <= inputDecimal;i++)
    {
      binaryNum = binaryNum << 1;
    }

    printf("Word length: %d bits\n", i + 1);

    for(j = 0; j <= i ; j++)
    {

      if(inputDecimal >= binaryNum)
      {
          binaryString[j] = '1';
          inputDecimal -= binaryNum;
      }
      else
      {
          binaryString[j] = '0';
      }

      binaryNum = binaryNum >> 1;

    }

    fprintf(stdout,"%s\n\n",binaryString);
  }
return 0;
}
