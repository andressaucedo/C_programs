#include<stdio.h>
#include<limits.h>
//this program finds the limits of different data types
int main()
{
short littleinteger=0;short littleintegerneg=0;
unsigned posinteger=0;
int integerminus=0; int integerplus=0;
long longdecimal=0; long longdecimalminus =0;
char character=0;char characterminus=0;
int i = 0;
int c;
      //char
        while(character >= 0){
          character = character +1;
          }
          character--;
        while(characterminus <= 0){
          characterminus = characterminus -1;
        }
        characterminus++;

      //short
        while(littleinteger >= 0){
          littleinteger = littleinteger +1;
          }
        littleinteger--;
        while(littleintegerneg <= 0){
          littleintegerneg = littleintegerneg -1;
        }
        littleintegerneg++;
        //int
        while(integerplus >= 0){
            integerplus = integerplus +1;
          }
        integerplus--;
        while(integerminus <= 0){
            integerminus = integerminus -1;
        }
        integerminus++;


//unsigned int
  while(posinteger <= (integerplus * 2)){
    posinteger = posinteger +1;
  }


//long
//      while(longdecimal <= ()){
//        longdecimal = longdecimal +1;
//        }
//      longdecimal--;
//      while(longdecimalminus <= 0){
  //      longdecimalminus = longdecimalminus -1;
    //  }
      //longdecimalminus++;

    printf("Data type limits on this machine:\n");
    printf("char      %d to %d\n",characterminus,character);
    printf("short     %d to %d\n",littleintegerneg,littleinteger);
    printf("int       %d to %d\n",integerminus,integerplus);
    printf("unsigned   0 to %u\n", posinteger);
    printf("long     %ld to %ld\n", LONG_MIN,LONG_MAX);
    printf("unsignlong 0 to %lu\a\n",(ULONG_MAX-1));
return 0;
}
