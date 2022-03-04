/**
 * @file Delay.h
 * @author Mukul Didolkar
 * @brief this project is about the customer billing system
 * @version 0.1
 * @date 2022-02-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#define DELAY_H
#include<stdio.h>
#include<time.h>
 
#define GOTOXY(x,y) printf("\033[%d,%df",y,x)
/**
 * @brief this function generates a delay for our file
 * 
 * @param time 
 */

void delay(int time)
{
  int milli = 1000 * time;
  clock();
  while (clock()<milli);  
}