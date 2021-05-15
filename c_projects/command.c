//command.c - copies a file using a system command
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

int main(void)
{
   char source[MAX];
   char target[MAX];
   char syscmd[MAX * 2 + 4];

   puts("Enter the name of the file you wish to copy:");
   fgets(source,MAX,stdin);
   source[strcspn(source,"\n")] = '\0';
   puts("Enter the desired name for the copy:");
   fgets(target,MAX,stdin);
   target[strcspn(target,"\n")] = '\0';

   sprintf(syscmd, "cp %s %s", source, target);
   printf("Executing the following command: %s\n",syscmd);
   system(syscmd);

return 0;
}
