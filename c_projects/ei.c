// ei.c - This program tabulates all the instances of "ei" in lower or upper case in a given input
#include<stdio.h>
#define MAX 1000

int main(void)
{
	int count,c; 		//control variables
	int ie_instances = 0;	//instance counter
	char input[MAX];	//input array
	
	printf("Enter your input. (# to quit):\n");
	// This loop fills the array with the input
	for(count=0; (c=getchar()) != '#';count++)
		input[count]=c;
	input[count] = '\0'; // mark end of string

	// This loop checks for "ei" and adds to instance counter
	for(count=0; input[count+1] != '\0'; count++)
		if((input[count]=='e' || input[count]=='E') && (input[count+1]=='i' || input[count+1]=='I'))
			ie_instances++;
	printf("The letters \"ei\" occur %d times.\n", ie_instances);

return 0;
}
