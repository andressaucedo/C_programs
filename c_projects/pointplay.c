#include<stdio.h>

int main(void)
{

  char array1[6] = "HELLO";
  char array2[2][6] ={
            {"hello"},
            {"THERE"}
  };

  char *point1;
  char *point2;

  printf( "contents of array1 as string: %s\n"
          "address of array1 as &array1: %p\n"
          "value at array[2] as *(array1 + 2): %c"
          "\n\n", array1, &array1,*(array1 + 2));
  point1 = array1;
  puts("pointer to char *point1 now points to array1 (array1[0]).");
  putchar('\n');
  printf( "contents of point1 as string: %s\n"
          "address of point1 as &point1: %p\n"
          "value pointed to by *(point1 + 2): %c"
          "\n\n", point1, &point1,*(point1 + 2));
  point2 = *array2;
  puts("Now let's try with a multidimensional array.");
  putchar('\n');
  printf( "contents of point2 as string: %s\n"
          "address of point2 as &point2: %p\n"
          "value pointed to by *( *(array2 + 1) + 3): %c"
          "\n\n", point2, &point2,*( *(array2 + 1) + 3));
  printf( "value of *array2 + 1 as string: %s \n"
          "value of **array2: %d \n"
          "value of *(++point2): %c \n", *array2+1, **array2, *(point2+1)+1);

return 0;
}
