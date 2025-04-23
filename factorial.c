#include <stdio.h>
/**
 * main - entry point of the program
 * description -  a proram that finds the factorials
 * of a given number
 * Return: always (0) success
 */
int main(void)
{
	int i, num;
	unsigned long long factorial = 1;
	
	printf("enter a non-negative integer\n");
	scanf("%d", &num);
	if (num < 0)
	{
		printf("factorial cannot be defined for negative numbers\n");
	}
	else if (num == 0)
	{
		printf("the factorial of 0 is 1\n");
	}
	else
	{
		for (i = 1; i <= num; i++)
		{
			factorial *=i;
		}
		printf("the factorial of %d is %llu\n", num, factorial);
	}
	return (0);
}
