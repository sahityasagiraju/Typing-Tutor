#include "typing_tutor.c"
#include<stdlib.h>
void main()
{
	int op;
	char name[15]={0};
	printf("Enter name:");
	scanf("%s",name);
	printf("Hi %s\n",name);
	while(1)
	{	
		printf("Enter 1 to type, 2 to view leader board, 3 to exit:");
		scanf("%d",&op);
		switch(op){
		case 1:type();break;
		case 2://sahitya's code
			break;
		case 3:exit(0);
		default:printf(CYN "Invalid Input\n" RESET);
		}
	}
}
