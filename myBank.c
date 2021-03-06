#include <stdio.h>

#define length 51
#define width 2


int sumAccounts = 0;
double accounts[length][width];

void open_account()
{
	if(sumAccounts < 50)
	{
		int i = 1;
		while(accounts[i][0] == 1)
		{
			i++;
		}

		double depo;
		printf("please enter amount for deposit: ");
		int check = scanf("%lf" , &depo);
		if(check != 1)
			printf("Failed to read the amount \n");
		
		else if(depo < 0)
			printf("Invalid Amount \n");	
			
		else 
		{
			accounts[i][0] = 1;
			accounts[i][1] = depo;
			printf("New account number is: %d \n",(i+900));
			sumAccounts++;
			}
	} 
	else
	{
		printf("failed to open an account \n");
	}
}

void balance_inquiry()
{
	int account ;
	printf("please enter the account number: ");
	scanf("%d", &account);
	if(account  <= 950 && account  > 900)
	{
		if(accounts[account - 900][0] == 1)
			printf("The balance of account number %d is: %.2lf \n",account , accounts[account-900][1]);
		else
			printf("This account is closed \n");
	}
	else
		printf("failed to find an account \n");

}

void deposit()
{
	int account ;
	printf("enter account number ");
	scanf("%d", &account);
	if(account  <= 950 && account  > 900)
	{
		if(accounts[account - 900][0] == 1)
		{
			double depo;
			printf("enter your deposit amount ");
			int check = scanf("%lf", &depo);
			if(check != 1)
				printf("Failed to read the amount \n");
		
			else
			{
				if(depo >= 0)
				{
					accounts[account - 900][1] += depo ;
					printf("the amount of the account is: %lf \n", accounts[account - 900][1]);
				}
				else 
					printf("failed to add the deposit \n");
			}
		}
		else
			printf("the account is closed \n");
	}
	else
		printf("failed to find an account \n");
}

void withdrawal()
{
	int account ;
	printf("please enter account number ");
	scanf("%d", &account);
	if(account  < 950 && account  > 900)
	{
		if(accounts[account - 900][0] == 1)
		{
			double withdraw;
			printf("please enter the amount to withdraw ");
			scanf("%lf", &withdraw);
			if(withdraw >= 0 && withdraw <= accounts[account - 900][1])
			{
				accounts[account - 900][1] -= withdraw;
				printf("the new balance is: %.2lf \n",accounts[account - 900][1]);
			}
			else
				printf("cannot withdraw more than the balance \n");
		}
		else
			printf("the account is closed \n");
	}
	else
		printf("failed to find an account \n");
}

void close_account()
{
	int account ;
	printf("enter account number ");
	scanf("%d", &account);
	if(account  <= 950 && account  > 900)
	{
		if(accounts[account - 900][0] == 1)
		{
			accounts[account - 900][0] = 0;
			accounts[account - 900][1] = 0;
			sumAccounts--;
			printf("account number %d successfuly closed \n", account);
		}
		else
		{
			printf("failed to close the account \n");
		}
		
	}
	else
		printf("failed to find an account \n");
}

void interest()
{
	double interests;
	printf("Please enter interest rate: \n");
	scanf("%lf", &interests);
	if(interests > 0)
	{
		for(int i = 1; i < length; i++)
		{
			if(accounts[i][0] == 1)
			{
				accounts[i][1] *= ((interests+100)/100);
			}
		}
	}
	else
		printf("failed to add interests \n");
}

void printAll()
{
	for(int i = 1 ; i < length ; i++)
	{
		if(accounts[i][0] == 1)
		{
			printf("the balance of the account number %d is: %.2lf \n", (i+900) , accounts[i][1]);
		}
	}
}

void close()
{
	if(sumAccounts > 0)
	{
		for(int i = 1 ; i < length ; i++)
		{
			if(accounts[i][0] == 1)
			{
				accounts[i][1] = 0;
				accounts[i][0] = 0;
			}
		}
	}
}


