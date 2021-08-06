#include<stdio.h>
int recur(int num);

int main(void)
{
int num;
	printf("Enter an integer please:\n");
	while(scanf("%d",&num) == 1){
		printf("The return value for the recursive function is: %d\n", (recur(num)));
	}
return 0;
}


int recur(int num)
{
	int ans;
	if(num == 1)
	return 1;

	else{
		ans = 2 + recur(num/2);	
		printf("%d\n",ans);
		return ans;
	}
}
