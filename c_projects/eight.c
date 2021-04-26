//eight.c - This program displays the ASCII code for characters in groups of N characters and N lines
#include <stdio.h>
#define LINE 8
#define BLOCK 4
int main(void)
{
	int input;
	int linecount = 0; //line counter
	int charcount = 0; //character counter
	printf("Enter characters to translate to decimal base integers. (# to quit):\n");

	while( (input=getchar()) != '#'){
		switch(input)
		{
			case '\n': 	//if input is ENTER then skip a line and reset counters
				printf("\n");
				charcount = linecount = 0;
				continue;

			default:	//if other characters are typed in 
				charcount++;
				printf("%d ",input);				
				if(charcount % LINE == 0){	//group into N character lines
					printf("\n");
					linecount++;
									
					if(linecount % BLOCK == 0) //group into N line blocks
						printf("\n");
					
				}

				break;
		}
	}

return 0;
}


