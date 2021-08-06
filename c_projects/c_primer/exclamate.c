//exclamate.c - This program substitutes spaces for exclamation marks and '!' for "!!"
#include<stdio.h>

int main(void)
{
	char input;
	int substitution;
	
	printf("Enter input and press Enter (# to quit):\n");
	while( (input=getchar()) != '#'){
		switch(input)
		{
			case ' ':
				input='!';
				printf("%c",input);
				substitution++;
				continue;

			case '!':
				printf("!!");
				substitution++;
				continue;
			default:
				printf("%c",input);
		}
				
/* This is the original version using if-else statements
 *
 * if(input == ' '){
			input = '!';
			printf("%c",input);
			substitution++;
			continue;
		}else if(input == '!'){
			printf("!!");
			substitution++;
			continue;
		}else

			printf("%c",input);
*/
		}
	printf("\nThere have been %d substitutions made.\n",substitution);
return 0;
}
