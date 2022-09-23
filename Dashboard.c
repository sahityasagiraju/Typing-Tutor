#include<stdio.h>
int main()
{int i ,a[5]={64,57,42,28,10};
char n[5][20]={"snigdha","sharmila","sahitya","aishwarya","hasini"};
FILE *fp1;
 fp1=fopen("file1.txt","w");
 fprintf(fp1,"%s   %s\n", "SCORE" , "NAME" );
for(i=0;i<5;i++)
  {
   fprintf(fp1,"%d     %s\n",a[i],n[i]);
  }
  fclose(fp1);
FILE *fp2=fopen("file1.txt","r");
char ch=fgetc(fp2);
while(ch!=EOF)
{
  printf("%c",ch);
   ch=fgetc(fp2);
}


 ch=fgetc(fp2);
 int m=ch-'0'; i=0;
 while((ch=fgetc(fp2))!=EOF)
  {
    if(isdigit(ch))
      a[i++]=ch-'0';
   }

   ch=fgetc(fp2);
 m=ch-'0'; i=0;
 while((ch=fgetc(fp2))!=EOF)
  {
    if(isdigit(ch))
      a[i++]=ch-'0';
   }

  i=0;
  int swap=1;
 while(i<m-1 && swap==1)
   {
     swap=0;
     for(int j=0;j<m-i-1;j++)
      if(a[j]>a[j+1])
       {
        int temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
         swap=1;
       }
     i++;
    }
   while(ch!=EOF)
{
  printf("%c",ch);
   ch=fgetc(fp2);
}

}
