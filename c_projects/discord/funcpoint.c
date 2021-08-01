#include <stdio.h>

typedef struct MyGreeting {
    void (* hello)(void);
    void (* welcome)(void);
} MyGreeting;

void english1(void);
void english2(void);
void spanish1(void);
void spanish2(void);

MyGreeting table1 = {
    .hello = english1,
    .welcome = english2,
};

MyGreeting table2 = {
    .hello= spanish1,
    .welcome = spanish2,
};

int main(void)
{
    int userSpeaksSpanish = 0;

    MyGreeting *p = &table1;
    if (userSpeaksSpanish) {
        p = &table2;
    }

    p->hello();
    p->welcome();

    return 0;
}

void english1(void)
{
    printf("Hello\n");
}

void english2(void)
{
    printf("Welcome\n");
}

void spanish1(void)
{
    printf("Hola\n");
}

void spanish2(void)
{
    printf("Bienvenido\n");
}
