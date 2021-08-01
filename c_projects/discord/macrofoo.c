#include <stdio.h>

#define LENGTH (10 + 20)
#define XSTRINGIFY(a) #a
#define STRINGIFY(a) XSTRINGIFY(a)

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define for_each(iterator, sbuf) \
    for (int i = 0, iterator = sbuf[0]; i < ARRAY_SIZE(sbuf); iterator = sbuf[i++])

int main(void)
{
    const char *a = STRINGIFY(LENGTH);
    int b = LENGTH * 10;

    char buf[] = "hello, world!";
    char c;

    for_each(c, buf) {
        printf("%c\n", c);
    }

    //printf("%s\n", a);
    //printf("%d\n", b);

    return 0;
}
