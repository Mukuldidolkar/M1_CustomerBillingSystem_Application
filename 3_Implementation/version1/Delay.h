
#define DELAY_H
#include<stdio.h>
#include<time.h>
 
#define GOTOXY(x,y) printf("\033[%d,%df",y,x)

void delay(int time)
{
  int milli = 1000 * time;
  clock();
  while (clock()<milli);  
}
