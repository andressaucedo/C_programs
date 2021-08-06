#include <stdio.h>
#define MAX 5000
#define LNLNG 80
  int input(char line[]);
  void copy(char to[],int index, char from[]);

// gets input line, returns line count to main
int input(char line[])
{
  int c, count;
  for (count=0;(c=getchar()) != EOF && c != '\n';count++) {
        line[count] = c;
    }
  if (c == '\n'){
        line[count] = c;
        ++count;
  }
  line[count] = '\0';
return count;
}

// copy array with index for last element in string
void copy(char to[],int index, char from[])
{

  ++index;
  while (from[index] != '\0'){
    to[index] = from[index];
    index++;
  }

}

// this program compares line lengths and returns the longest
int main()
{
char currentline[MAX];
char longline[MAX];
int length = 0; int rc = 0; int a, b, c;

  while((length = input(currentline)) > 0){
    if(length > LNLNG){
      rc = (rc + length);
      copy(longline,rc,currentline);
    }
  }
printf("\n%s\n", longline);

for (a = 0, b =1; a < rc; a++, b++){
  if (longline[a] != '\t'&& longline[a] != ' '){
    printf("%c", longline[a]);
  }else if (longline[a]==' ' && longline[b]!=' ' && longline[b]!='\t'){
    printf("%c", longline[a]);
  }else if (longline[a] == '\t'){
    longline[a] = ' ';
    --a, --b;
  }
}
   return 0;
}
