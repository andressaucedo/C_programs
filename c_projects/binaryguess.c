/***********************************************************************************************************
 * binaryguess.c - This program uses a binary search to guess a number the user has chosen		   *
 **********************************************************************************************************/
#include<stdio.h>
#define MAX 100
void ignore_string_tail(void); //this function ignores input after the first character until Enter is pressed.

int main(void)
{
	int high = MAX; 		//set starting high end of range
	int low = 0;			//set starting low end of range
	int mid = (high + low)/2;	//set midpoint (current position for testing)
	int input, high_or_low;

	printf("Hey there! This program guesses a number that you're thinking "
		"of using a binary search algorithm.\n"
		"Please think of a number between 1-%d now...\n\n",MAX);
	printf("Is your number %d?: ",mid);
	while((input=getchar()) != 'y' || input == 'Y'){
		ignore_string_tail();

      		if(input == 'n' || input == 'N'){
			
			printf("Is it higher or lower?\n");
			(high_or_low = getchar());
        		ignore_string_tail();
        		
			if(high_or_low == 'h' || high_or_low == 'H'){
				low = mid;		//set new low end
				mid = (low+high)/2;	//set new midpoint (high is same as previous)
			}else if( high_or_low == 'l'|| high_or_low == 'L'){
				high = mid;		//set new high point
				mid = (low+high)/2;	//set new midpoint (low is same as previous)
			}
		}

	printf("Is your number %d?: ",mid);	//checks agains new midpoint and loop starts again
	}



printf("\nYour number is %d!\n",mid);
return 0;
}

void ignore_string_tail(void)
{
   while(getchar() != '\n')		//this self contained loop ignores all
      continue;       			//input after the first character.

}
