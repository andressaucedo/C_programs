#include<stdio.h>
#define MAX 1000
  int getl(char line[], int index);
//void concat(char lin1, char lin2, int index);

// grab a line from input and return the element count + 1 for '\0'
int getl(char line[], int index){
int i = index; int c = 0;

  while((c = getchar()) != EOF && c !='\n'){
        line[i]=c;
        ++i;
    }if(c == '\n'){
        line[i]=c;
        i++;
        line[i]='\0';
    }

return i;
}

// this program concatenates multiple lines
int main()
{
char ln[MAX]; char ln2[MAX];
int length = 0;int save = 0;
int i, x, z;

  for(i=0, x=1, z=save; (length = getl(ln, z)) > 0; i++, x++, z++){
    if(ln[i] != '\0'){
        ln2[z] = ln[i];
printf("\n%s\n", ln2);
    }else if(ln[i] == '\0'){
        i++;
        save = (save + i);
    }else if(ln[i] == ':' && ln[x] == 'q' && ln[(x+1)] == '\n'){
        goto END;
    }
  }

END:
printf("\n%s\n", ln2);
return 0;
}


// concatenate two arrays
//void concat(char lin1, char lin2, int index){

//}
