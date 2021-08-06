//raceconvert.c - This program takes a time for a metric race and converts
//the time and rate for it's equivalent in a miles race
#include<stdio.h>
#include<string.h>
#define SECMIN 60   //seconds per minute
#define SECHR 3600 //seconds per hour
#define MIKM 0.612137   //miles per km

int main(void)
{
   float distance_km,distance_mi,mph,kph;
   float pace_mi_min,pace_mi_sec;
   int hours,minutes, seconds;

   printf("This program converts your time for a metric race\n"
   "to a time for running a race in miles.\n"
   "It calculates distance, kph/mph and your pace per mile.\n\n"
   "Enter distance run in kilometers.\n");
   scanf("%f", &distance_km);
   printf("\nNext, enter your time in clock format \n"
   "for hours,minutes and seconds \n"
   "and press Enter (example: 0:25:34)\n");
   scanf("%2d:%2d:%2d",&hours,&minutes,&seconds);

   minutes += (hours * SECMIN); //convert hours to minutes
   seconds += (minutes * SECMIN); //convert minutes to seconds
   distance_mi = distance_km * MIKM; //convert kilometers to miles
   //divide seconds in an hour by seconds run, multiply by distance
   kph = (SECHR / (float)seconds) * distance_km;
   mph = (SECHR / (float)seconds) * (distance_km * MIKM);
   //find seconds run in a mile, convert to minutes with remainder
   pace_mi_min = ((float)seconds/distance_mi)/SECMIN;
   //subtract remainder from minutes and convert to seconds
   pace_mi_sec = ((float)pace_mi_min - (int)pace_mi_min) * SECMIN;

   printf("\n%2.2fkm/%2.2fmi total distance\n",distance_km, distance_mi);
   printf("%2.2fkph/%2.2fmph\n",kph,mph);
   printf("%d:%02d mile pace\n",(int)pace_mi_min, (int)pace_mi_sec);

   return 0;
}
