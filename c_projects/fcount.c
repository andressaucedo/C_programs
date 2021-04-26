// fcount.c - counts all the characters in input until the EOF (end of file)
#include<stdio.h>

int main(void)
{
	int c, char_count,i;

	for( char_count=0; (c=getchar()) != EOF; char_count++){
		for(i=0;i<100;i++)//delay loop
			;
		fprintf(stdout,"\a");
	}
	printf("\n%d characters counted.\n",char_count);

}

