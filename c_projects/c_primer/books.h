//header for use with booksave.c
#define MAXWRD 40
#define MAXBKS 10

struct book {
  char title[MAXWRD];
  char author[MAXWRD];
  float price;
};
