/**
 * @file Delay.h
 * @author Mukul Didolkar (you@domain.com)
 * @brief 
 * @version 0.1

 * 
 * @copyright Copyright (c) 2022
 * 
 */
#define DELAY_H
#include<stdio.h>
#include<time.h>
/**
 * @brief defines the delay in time
 */
 
#define GOTOXY(x,y) printf("\033[%d,%df",y,x)

void delay(int time)
{
  int milli = 1000 * time;
  clock();
  while (clock()<milli);  
}
/**
 * @brief milli is an integer here 
 * @return clock as a void function
 */