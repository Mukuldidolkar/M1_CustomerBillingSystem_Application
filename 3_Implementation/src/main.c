 /**
 * @file main.c
 * @author Mukul Didolkar
 * @brief This is the main file of our project Customerbilling system
 * @version 0.1
 * @date 2022-02-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */
 #include"Delay.h"
 #include<stdio.h>
 #include<string.h>
 #include<stdlib.h>
 #include<time.h>
 void input();
 void Writefile();
 void search();
 void output();

 struct date{
	   int month;
	   int day;
	   int year;
	   };
/**
 * @brief this is a structure date where we have integer values like month,day,year
 * 
 */
  struct account {
	int number;
	char name[100];
	int acct_no;
	float mobile_no;
	char street[100];
	char city[100];
	char acct_type;
	float oldbalance;
	float newbalance;
	float payment;
	struct date lastpayment;
  }customer;
  int tl,sl,ts;
 void main()
	{
	  int i,n;
	  char ch;
	  system("clear");

	  
	  printf("   CUSTOMER BILLING SYSTEM:\n\n");
	  printf("===============================\n");
	  printf("\n1:    to add account on list\n");
	  printf("2:    to search the customer account\n");
	  printf("3:    exit\n");
	  printf("\n================================\n");

	  do
	  {
	       printf("\nselect what do you want to do?");
	       ch=getchar();
	  } 
	  /**
	   * @brief to ask the customer his/her choice
	   * 
	   */
	  while(ch<='0' || ch>'3');
	  switch(ch)
	  {
		case '1':
			system("clear");
			printf("\n how many customer accounts : ");
			scanf("%d",&n);
			getchar();
			for(i=0;i<n;i++)
			{
				input();
				if(customer.payment > 0.0) 
					customer.acct_type=(customer.payment<customer.oldbalance)? 'O': 'D';
				else
					customer.acct_type=(customer.oldbalance>0)?'D' : 'C';
				customer.newbalance=customer.oldbalance - customer.payment;
				Writefile();
			}
			main();
		case '2':
			getchar();
			system("clear");
			printf("search by what ??\n\n");
			printf("1 --- search by customer number\n");
			printf("2 --- search by customer name\n");
			search();
			ch=getchar();
			main();
		case '3':
			system("clear");
			delay(500);
			
			GOTOXY(10,25);
			delay(1500);
			exit(1);
	  }
 }


   void input()
	{
	  FILE *fp=fopen("file.txt","ab+");
	  fseek (fp,0,SEEK_END);
	  tl=ftell(fp);
	  sl=sizeof(customer);
	  ts=tl/sl;
	  fseek(fp,(ts-1)*sl,SEEK_SET);
	  fread(&customer,sizeof(customer),1,fp);
	  printf("\ncustomer no:%d\n",++customer.number);
	  fclose(fp);
	  printf("         Account number: ");
	  scanf("%d",&customer.acct_no);
	  getchar();
	  printf("\n       Name:");
	  scanf("%s",customer.name);
	  getchar();
	  printf("\n       mobile no:");
	  scanf("%f",&customer.mobile_no);
	  getchar();
	  printf("         Street:");
	  scanf("%s",customer.street);
	  getchar();
	  printf("         City:");
	  scanf("%s",customer.city);
	  getchar();
	  printf("         Previous balance:");
	  scanf("%f",&customer.oldbalance);
	  getchar();
	  printf("         Current payment:");
	  scanf("%f",&customer.payment);
	  getchar();
	  printf("         Payment date(mm/dd/yyyy):");
	  scanf("%d/%d/%d",&customer.lastpayment.month,&customer.lastpayment.day,&customer.lastpayment.year);
	  getchar();
	  return;
   }

   

   void search()
   {
	 char ch;
	 char nam[100];
	 int n,i,m=1;
	 FILE *fp;
	 fp=fopen("file.txt","r+");
	 do{
		printf("\nenter your choice:");
		ch=getchar();
	 }while(ch!='1' && ch!='2');
	 switch(ch)
	 {
	      case '1':
		    fseek(fp,0,SEEK_END);
		    tl=ftell(fp);
		    sl=sizeof(customer);
		    ts=tl/sl;
		    do{
			printf("\nchoose customer number:");
			scanf("%d",&n);
			if(n<=0 || n>ts)
			printf("\nenter correct\n");
			else{
			    fseek(fp,(n-1)*sl,SEEK_SET);
			    fread(&customer,sl,1,fp);
			    output();
			}
			printf("\n\nagain?(y/n)");
			ch=getchar();
		    }while(ch=='y');
		    fclose(fp);
		    break;
	      case '2':
		    fseek(fp,0,SEEK_END);
		    tl=ftell(fp);
		    sl=sizeof(customer);
		    ts=tl/sl;
		    fseek(fp,(ts-1)*sl,SEEK_SET);
		    fread(&customer,sizeof(customer),1,fp);
		    n=customer.number;

		    do{
			printf("\nenter the name:");
			scanf("%s",nam);
			fseek(fp,0,SEEK_SET);
			for(i=1;i<=n;i++)
			{
			     fread(&customer,sizeof(customer),1,fp);
			     if(strcmp(customer.name,nam)==0)
			     {
				output();
				m=0;
				break;
			     }
			}
			if(m!=0)
			printf("\n\ndoesn't exist\n");
			printf("\nanother?(y/n)");
			ch=getchar();
		    }while(ch=='y');
		    fclose(fp);
	      }
	      return;
	 }
	 /**
	  * @brief search for the given choice and ask the customer to search another account yes or no?
	  * 
	  */



   void output()
	 {
	   printf("\n\n    Customer no    :%d\n",customer.number);
	   printf("    Name 	   :%s\n",customer.name);
	   printf("    Mobile no      :%.f\n",customer.mobile_no);
	   printf("    Account number :%d\n",customer.acct_no);
	   printf("    Street         :%s\n",customer.street);
	   printf("    City           :%s\n",customer.city);
	   printf("    Old balance    :%.2f\n",customer.oldbalance);
	   printf("    Current payment:%.2f\n",customer.payment);
	   printf("    New balance    :%.2f\n",customer.newbalance);
	   printf("    Payment date   :%d/%d/%d\n\n",customer.lastpayment.month,customer.lastpayment.day,customer.lastpayment.year);
	   printf("    Account status :");
	   
	   switch(customer.acct_type)
	      {
	      case 'C':
		 printf("CURRENT\n\n");
		 break;
	      case 'O':
		 printf("OVERDUE\n\n");
		 break;
	      case 'D':
		 printf("DELINQUENT\n\n");
		 break;
	      default:
		 printf("ERROR\\n\n");
	      }
	      
	      return;
	   }
	   /**
	    * @brief to dispay the output as the status of the account of the customer
	    * 
	    */













