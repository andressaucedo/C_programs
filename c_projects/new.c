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
   int minutes, seconds;

   printf("This program converts your time for a metric race\n"
   "to a time for running a mile and to your average\n"
   "speed in miles per hour.\n\n"
   "Please enter, in kilometers, the distance run.\n");
   scanf("%f", &distance_km);
   printf("Next, enter the time in minutes and seconds.(example: 25:34)\n");
   scanf("%2d:%2d",&minutes,&seconds);

   distance_mi = distance_km * MIKM;
   seconds += (minutes * 60);
   kph = (SECHR / (float)seconds) * distance_km;
   mph = (SECHR / (float)seconds) * (distance_km * MIKM);
   pace_mi_min = ((float)seconds/distance_mi)/SECMIN;
   pace_mi_sec = ((float)pace_mi_min - (int)pace_mi_min) * SECMIN;

   printf("\n%2.2fkm/%2.2fmi total distance\n",distance_km, distance_mi);
   printf("%2.2fkph/%2.2fmph\n",kph,mph);
   printf("%d:%02d mile pace\n",(int)pace_mi_min, (int)pace_mi_sec);

   return 0;
}
