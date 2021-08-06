#include<stdio.h>
#define HI 12
//HI should be set to multiples of 4
void calc(int input, int values[], int binary[]);
int maxinput(int values[]);
//this program converts decimal numbers to binary expressions
int main()
{
int values[HI]; //array holding the decimal values of each binary place
int binary[HI]; //the array that outputs as the actual binary number
int i,k,input,m;
k=1; //variable for leftmost value
   for(i=HI-1; i >= 0; i--){ //set the values and initialize binary array
      values[i]=k;
      binary[i]=0;
      k=k*2;
   }

   while(input != EOF){
      for(i=0;i<HI;i++) // resets binary array for next input
         binary[i]=0;
      printf("Enter integer to convert:\n");
      scanf("%d",&input);
      if(input > (m = maxinput(values))){ //if input exceeds max value
         printf("Error: input value exceeds max of %d\n", m);
         input = 0;
      }
      calc(input,values,binary);

      for(i=0; i < HI ; i++){
         if(i%4 == 0){
            printf("  ");
         }
         printf("%5d ", values[i]);
      }
      putchar('\n');
      for(i=0; i < HI ; i++){
         if(i%4 == 0){
            printf("  ");
         }
         printf("%5d ", binary[i]);
      }
      putchar('\n');
      }
return 0;
}

//this function calculates the input to binary
void calc(int input, int values[], int binary[])
{
int i;
   //find highest value bit to turn on
   for(i=HI-1; input > values[i]; i--){}

   while(i < HI){
      //if input is == or >= than a bit value & less than next higher value
      if(input == values[i] || input >= values[i] && input < values[i-1]){
         input= input % values[i]; //remainder becomes input
         binary[i] = 1;//mark binary position to ON
         i++;//move right to next lower value
      }else{
         i++;
      }
   }
}
//this function calculates the maximum input value allowed
int maxinput(int values[])
{
int i, max;
max = 0;

   for(i= HI;i >= 0; i--){
      max += values[i];
   }
++max;

return max;
}
