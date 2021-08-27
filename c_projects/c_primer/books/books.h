//header for use with booksave.c
#define MAXWRD 128 //!!! edits will change struct size, make new .dat
#define MAXBKS 10
#define YES 1
#define NO 0
#define OTHER 2

struct book {
  char title[MAXWRD];
  char author[MAXWRD];
  float price;
};
