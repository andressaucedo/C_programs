//header for use with booksave.c
#define MAXWRD 128 //!!! edits will change struct size, make new .dat
#define MAXBKS 10

struct book {
  char title[MAXWRD];
  char author[MAXWRD];
  float price;
};
