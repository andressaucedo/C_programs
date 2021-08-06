#include<stdio.h>
float recur(float *num, int top);
int max;
int main(int argc, char const *argv[])
{
  int top = 0;
  float nums[] = {3.4, 5.4, 44.4, 75, 4.5, 2, 56, 34, 9.33};
  extern int max;
  max = ( sizeof(nums)/sizeof(nums[0]) );
  printf("%d items in array\n\n", max);

  recur(nums, top);
  for(int i = 0; i < max; i++){
    fprintf(stdout,"%.3f\n",nums[i]);
  }
  return 0;
}

/* function sorts items in an array recursively */
float recur(float *num, int top)
{
  float temp;
  int index = top + 1;
  extern int max;

    while(top < max && index < max)
    {
      if(num[top] > num[index]){
        temp = num[top];
        num[top]= num[index];
        num[index] = temp;
      }
      index++;
    }

    if(top < max)
    {
      recur(num,(top + 1));
    }

    return top;
}
