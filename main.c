#include<stdio.h>
#include "myBank.c"


int main()
{
	char p = '1';
	while(p != 'E')
	{
		printf("please choose a transaction type: \n O - open acount \n B - balnce inquiry \n D deposit \n W - Withdrawal \n C - Close acount \n I - Interest \n P - Print \n E - Exit \n"); 
		int check = scanf(" %c ", &p);
		if(check !=1)
			printf("invalid transaction type \n");
		else if(p == 'O')
		{
			open_account();
			printf("\n");
			}
		else if(p == 'B')
		{
			balance_inquiry();
			printf("\n");
			}
		else if(p == 'D')
		{
			deposit();
			printf("\n");

}
		else if(p == 'W')
		{
			withdrawal();
			printf("\n");
			}
		else if(p == 'C')
		{
			close_account();
			printf("\n");
			}
		else if(p == 'I')
		{
			interest();
			printf("\n");
			}
		else if(p == 'P')
		{
			printAll();
			printf("\n");
			}
		else if(p == 'E')
			close();
		else 
			printf("invalid transaction type \n"); 
			
	}
	return 0;
}
