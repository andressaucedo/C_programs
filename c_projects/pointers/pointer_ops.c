// pointer_ops.c -- This program illustrates the 5 possible operations C can perform on pointer variables
#include<stdio.h>

int main(void)
{
	static int urn[3] = {100,200,300};
	int *point1, *point2;
	printf("size of int = %ld bytes\n",sizeof(int));

	point1 = urn;		//point1 now points to &urn[0]
	point2 = &urn[2];	//point2 now points to &urn[2] or *urn+2
	
	printf("point1= %p\t*point1= %d\t&point1= %p\n", point1,*point1,&point1);
	printf("\nincrementing : point1++\n");
	point1++;
	printf("point1= %p\t*point1= %d\t&point1= %p\n", point1,*point1,&point1);
	printf("point2= %p\t*point2= %d\t&point2= %p\n", point2,*point2,&point2);
	
	printf("\nexceeding bounds with: point2++\n");
	++point2;		
	printf("point1= %p\t*point1= %d\t&point1= %p\n", point1,*point1,&point1);
	printf("point2= %p\t*point2= %d\t&point2= %p\n", point2,*point2,&point2);
	printf("Pointer subtraction\n"
		"point2 - point1 = %ld\n",point2 - point1);

	return 0;
}

