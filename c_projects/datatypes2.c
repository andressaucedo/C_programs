#include<stdio.h>
#include<limits.h>
//this program finds the limits of different data types
int main()
{

    printf("Data type limits on this machine:\n");
    printf("char      %d to %d\n",CHAR_MIN,CHAR_MAX);
    printf("short     %d to %d\n",SHRT_MIN,SHRT_MAX);
    printf("int       %d to %d\n",INT_MIN,INT_MAX);
    printf("unsigned   0 to %u\n", UINT_MAX);
    printf("long     %ld to %ld\n", LONG_MIN,LONG_MAX);
    printf("unsignlong 0 to %lu\a\n",(ULONG_MAX));
return 0;
}
