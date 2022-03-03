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