#include<stdio.h>
#include<string.h>

int main(void)
{
   char *a = "Beast!";
   char b[] ="Be the best you can be!";

   puts(b);
   strcpy(b + 7, a);
   puts(b);
return 0;
}
