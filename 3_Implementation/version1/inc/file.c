/**
 * @file file.c
 * @author Mukul Didolkar
 * @brief 
 * @version 0.1
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>
 char customer[100];
 void writefile()
   {
	  FILE *fp;
	  fp=fopen("file.txt","ab+");
	  fwrite(&customer,sizeof(customer),1,fp);
	  fclose(fp);
	  return;
   }