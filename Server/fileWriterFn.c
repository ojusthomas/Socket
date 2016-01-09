#include <stdio.h>
#include <stdlib.h>  /* For exit() function */
int writeToFile(char * filename,char * text)
{
   char c[1000];
   FILE *fptr;
   printf("\n Inside writeToFile");
   fptr=fopen(filename,"w");
   if(fptr==NULL){
      printf("Error!");
      exit(1);
   }
   //printf("Enter a sentence:\n");
   //gets(c);
   fprintf(fptr,"%s",text);
   fclose(fptr);
   return 0;
}
