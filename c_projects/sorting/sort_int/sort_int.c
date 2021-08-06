/* sort_int.c -- sorts integers in an array */
#define MAXSIZE 100     //limit to number of integers to sort
extern int getarray(int ar[], int n);
extern void sort(int ar[], int n);
extern void print(int ar[], int n);

int main(void)
{
  int numbers[MAXSIZE];   //array to hold input
  int size;               //number of input items

  size = getarray(numbers, MAXSIZE);  //get input for array
  sort(numbers,size);                 //sort the array
  print(numbers,size);                //print the sorted array

  return 0;
}
