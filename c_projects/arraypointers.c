#include<stdio.h>
#define SIZE 4
void printone(int *array);
void printdub(int *array);

int main(void)
{
	int nums[4] = {1,2,3,4};
	int dubnums[2][4] ={
		{5,10,8,7},
		{9,10,11,12}};
   int *dubs;
   dubs = &dubnums[0][0];
//	printf("nums = %p\n"
//		"*nums = %d\n"
//		"&nums = %p\n",nums,*nums,&nums);

	printone(nums);
	putchar('\n');
	printdub(dubs);

   printf("\n*dubs = %d\n",*dubs); //value located at dubs or &dubnums[0][0]
   printf("*dubs + 1 = %d\n",*dubs + 1); // add 1 to value at dubs
   printf("*dubs = %d\n",*dubs);
   printf("*++dubs = %d\n",*++dubs); //go to next element
   printf("*dubs++ = %d\n",*dubs++); //go to next element after current operator
   printf("*dubs = %d\n",*dubs);
   printf("*(dubs++) = %d\n",*(dubs++)); //same as *dubs++
   printf("*dubs = %d\n",*dubs);
   printf("*(dubs + 4) = %d\n",*(dubs+4)); //same as *dubs++
   printf("*dubs = %d\n",*dubs);


return 0;
}

void printone(int *array)
{
	for(int i = 0; i < SIZE; i++)
		printf("%d %p\n", *(array + i),&array[i]);
	putchar('\n');
}

void printdub(int *array)
{
	for(int i =0; i < (SIZE*2); i++)
		printf("%d %p\n", *(array++), &array[i]);
	putchar('\n');
}
