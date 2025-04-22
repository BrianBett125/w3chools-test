#include <stdio.h>
/**
 * main - entry point of the program
 * description: a program to compare two numbers
 * Return:  always (0) success
 */
int main(void)
{
	int num1, num2;

	printf("enter the first digit\n");
	scanf("%d", &num1);
	printf("enter the second digit\n");
	scanf("%d", &num2);
	if (num1 == num2)
	{
		printf("both digits are equal\n");
	}
	else if (num1 > num2)
	{
		printf("the greater number is %d\n", num1);
		printf("the smaller number is %d\n", num2);
	}
	else
	{
		printf("the greater number is %d\n", num2);
		printf("the smaller is %d\n", num1);
	}
	return (0);
}
