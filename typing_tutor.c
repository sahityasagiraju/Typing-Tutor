#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define RED   "\x1B[31m"
#define KBLU  "\x1B[34m"
#define CYN   "\x1B[36m"
#define KYEL  "\x1B[33m"
#define KMAG  "\x1B[35m"
#define KGRN   "\x1B[32m"
#define RESET "\x1B[0m"
#include<string.h>
int compareFiles(FILE *fp1, FILE *fp2) ;
void type()
{
	FILE *f,*fp,*f1,*f2;
	int level,m,n;
	clock_t start,end;
	double cputime;
	printf(CYN "Select difficulty level(1:easy,2:intermediate,3:hard)\n" RESET);
	scanf("%d",&level);
	switch(level){
	case 1:f=fopen("easy.txt","r");
		   if(f==NULL){
		   		printf("Error");
		   		exit(0);
		   }
		 break;
	case 2:f=fopen("intermediate.txt","r");
		   if(f==NULL){
		   		printf("Error");
		   		exit(0);
		   }
		   break;
	case 3:f=fopen("hard.txt","r");
		   if(f==NULL){
		   		printf("Error");
		   		exit(0);
		   }
		   break;
	}
	fp=fopen("user.txt","w");
	
	char c=fgetc(f);
	char str[200];
	while(c!=EOF)
	{
		printf(KYEL "%c" RESET,c);
		c=fgetc(f);
	}
	printf(KGRN "\nPress 1 and start typing and press 0 once done\n\n" RESET);
	int i=0,in;
	scanf("%d",&in);
	start=clock();
	scanf("%c", &str[i]);
	while(str[i]!='0')
	{
		fputc(str[i],fp);
		i++;
		scanf("%c", &str[i]);
		
	}
	end=clock();
	cputime=((double)(end-start))/CLOCKS_PER_SEC;
	printf("time taken=%lf\n",cputime);
	fclose(f);
	fclose(fp);
	switch(level){
	case 1:f1=fopen("easy.txt","r");
		   if(f==NULL){
		   		printf("Error");
		   		exit(0);
		   }
		 break;
	case 2:f1=fopen("intermediate.txt","r");
		   if(f==NULL){
		   		printf("Error");
		   		exit(0);
		   }
		   break;
	case 3:f1=fopen("hard.txt","r");
		   if(f==NULL){
		   		printf("Error");
		   		exit(0);
		   }
		   break;
	}
	
	f2=fopen("user.txt","r");
	int errors=compareFiles(f1,f2);
	int correct=i-errors;
	printf("number of correct=%d\n",correct);
}
	

int compareFiles(FILE *fp1, FILE *fp2) 
{ 
    // fetching character of two file 
    // in two variable ch1 and ch2 
    char ch1 = getc(fp1); 
    char ch2 = getc(fp2); 
    
    // error keeps track of number of errors 
    // pos keeps track of position of errors 
    // line keeps track of error line 
    int error = 0, pos = 0, line = 1; 
  
    // iterate loop till end of file 
    while (ch1 != EOF && ch2 != EOF) 
    { 
        pos++; 
  
        // if both variable encounters new 
        // line then line variable is incremented 
        // and pos variable is set to 0 
        if (ch1 == '\n' && ch2 == '\n') 
        { 
            line++; 
            pos = 0; 
        } 
  
        // if fetched data is not equal then 
        // error is incremented 
        if (ch1 != ch2) 
        { 	
            error++; 
            printf("Line Number : %d \tError Position : %d \t %c entered instead of %c\n",line,pos,ch2,ch1); 
        } 
  
        // fetching character until end of file 
        ch1 = getc(fp1); 
        ch2 = getc(fp2); 
    } 
  
    printf(RED "Total Errors : %d\t" RESET, error); 
    return error;
} 
  
