/*ccount.c-This program counts characters,words,lines,blanks and outputs the count*/
#include<stdio.h>
#define IN 1
#define OUT 0

int main(void)
{	
	int space,tab,line,word,other;
	line=1;
	space=word=tab=other=0;	//counter variables
	char c;				//input variable
	int wordstate = OUT;		//variable to tell us when a word starts
	
	printf("Enter your input or type # and enter to quit:\n");
	while( (c=getchar()) != '#')
	{
		switch(c)
		{
			case ' ':
				space++;
				wordstate=OUT;
				break;
			case '\t':
				tab++;
				wordstate=OUT;
				break;
			case '\n':
				line++;
				wordstate=OUT;
				break;
			default:
				if(wordstate==OUT)
					word++;
				wordstate=IN;
				other++;
				break;
		}
	}
	printf("Your input has:\n\t\t %d characters, %d words, %d lines\n\t\t %d spaces and %d tabs\n", other, word, line, space, tab);
	printf("Goodbye.\n");

return 0;
}
