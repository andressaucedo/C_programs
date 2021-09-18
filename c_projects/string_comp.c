#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char stringB[] = {"cool\0"};
    puts(argv[1]);
    int val = strcmp(argv[1],stringB);
    if(!val)
    {
        puts("evaluated");
    }
    printf("%d\n",val);
}