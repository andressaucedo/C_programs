#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
  char * foo;
  int flag = strtol(argv[1],&foo,2);
  typedef enum ID{
    id_a = 1 << 1, 
    id_b = 1 << 2,
    id_c = 1 << 3,
    id_d = 1 << 4,
  } myid;
 
    printf("flag = %d\n", flag);
    flag = (flag << 1);
    printf("flag << 1 = %d\n", flag);
    flag = (flag ^ 4);
    printf("flag ^ 4 (100 binary) = %d\n", flag);
    flag = ( flag | flag-1);
    printf("flag | flag - 1 = %d\n", flag);

    return 0;
}