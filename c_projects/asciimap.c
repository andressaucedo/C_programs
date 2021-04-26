//asciimap.c - prints all input characters and their ASCII values until EOF
#include<stdio.h>
#define SPACE 32
#define LINEFEED 10
#define TAB 9

int main(void)
{
	int input,count;
	
	while( (input=getchar()) != EOF){
		if(count == 10){
			printf("\n");
			count = 0;
		}
		if(input < SPACE && input != LINEFEED && input != TAB){
			printf("%d ^%c   ",input, (input + 64));
			count++;
		}
		else if(input == ' '){
			printf("%d ' '   ",input);
			count++;
		}
		else if(input == '\t'){
			printf("%d '\\t'   ",input);
			count++;
		}
		else if(input == '\n'){
			printf("%d '\\n'\n", input);
			count = 0;
		}
		else{
			printf("%d %c   ",input,input);
			count++;
		}
	}
	putchar('\n');

return 0;
}
