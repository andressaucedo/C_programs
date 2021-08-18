/* funcpoint.c - program illustrating the use of function pointers*/
#include <stdio.h>
#include <stdlib.h>

int rputs(const char * string);
void show( int (*funcPoint)(const char *position), const char *string);
/* *position points to the name of function while *funcpoint points to
  the address of the function itself */

int main(int argc, char const *argv[])
{
  if(argc < 2)
  {
    fprintf(stderr,"ERROR: missing arguments\n"
            "USAGE:\n"
            "%s [STRING]\n"
            "[STRING] - user defined word to output to stdout"
            "\n", argv[0]);
    exit(1);
  }

  for(int i = 1; i < argc; i++)
  {
  show(puts, argv[i]); //print command line arguments
  show(rputs, argv[i]); //print reverse command line arguments
  }

  return 0;
}

/*rputs() - function that takes a pointer to a character as an argument
  and outputs the string it points to backwards*/
  int rputs(const char * string)
  {
    const char * start = string; //pointing to first character
    int count;

    while(*string != '\0' && *string != '\n')
    {
      string++; //iterate through string until the ending null char
      count++; //counting number of characters
    }

    while(string != start)
    {
      //print characters until string position is the same as our start
      putchar(*--string);
    }
    putchar('\n');

    return count;
  }

  /* show() function passes arguments to puts or rputs */
  void show(int (*funcPoint)(const char *position),const char *string)
  {
    (*funcPoint)(string);
     //passes address to string to address to function
  }
