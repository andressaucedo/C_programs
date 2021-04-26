// wordavg.c - this program reads input until EOF and calculates the average word size
#include<stdio.h>
#define IN 1
#define OUT 0
#define MAX 2000

int main(void)
{	
	int input,ct;			//input and counter
	int wordstate;			//variable for in or out of a word 
	int charcount, wordcount;	//character and word counters
	int wordlength[MAX]; 		//array to hold character count of each word
	int total, average;		//total of all word characters, total/wordcount
	ct = wordcount = charcount = 0;
	
	wordstate = OUT;		//state of word is assumed as OUT
	printf("This program finds the average word length of your input (Ctrl+D to end):\n");
	while( (input = getchar()) != EOF){	
		//Don't count blanks or punctuation, set word to OUT, log word length and reset char. count
		if(input == ' ' || input == '\t' || input == '\n'){
			if(wordstate == IN){
				wordstate = OUT;
				wordlength[ct++] = charcount;
				charcount = 0;
			}		
			continue;		
		}else if(input == ',' || input == '.' || input == '?' || input == '!'){
			
			if(wordstate == IN){
				wordstate = OUT;
				wordlength[ct++] = charcount;
				charcount = 0;
			}		
			continue;
		//If the state is OUT but input is a valid character, increment word & character count
		}else if(wordstate == OUT){
			wordstate = IN;
			wordcount++;
			charcount++;
		//If state is IN the middle of a word, increment character count
		}else if(wordstate == IN){
			charcount++;
		}
	}
	wordlength[ct] = charcount;	//In case the file is ended with EOF and no blank/punctuation
	
	//Calculate the total and average
	for(ct=0; ct <= wordcount; ct++)
		total+=wordlength[ct];
	average = total / wordcount;

	printf("\nYour input has %d words. The average word length is %d\n",wordcount, average);
	
	for(ct=0; ct < wordcount; ct++)
		printf("%d ",wordlength[ct]);
	putchar('\n');
return 0;
}
