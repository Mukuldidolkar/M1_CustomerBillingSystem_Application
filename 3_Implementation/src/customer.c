 /**
 * @file customer.c
 * @author Mukul Didolkar
 * @brief this file tells us about writefile
 * @version 0.1
 * @date 2022-03-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
 #include<stdio.h>
 char customer[100];
 void Writefile()

   {
	  FILE *fp;
	  fp=fopen("file.txt","ab+");
	  fwrite(&customer,sizeof(customer),1,fp);
	  fclose(fp);
	  return;
   }
   /**
    * @brief this function writes the details of the customer on the file
    * 
    */