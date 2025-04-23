#include <stdio.h>
/**
 * main - entry point of the program
 * description - a program to print all elements in a fibonacci series
 * Return: always (0) success
 */
int main(void)
{
	int i, n, next, first = 0, second = 1;

	printf("enter the number of terms\n");
	scanf("%d", &n);
	printf("fibonacci series: ");
	for (i = 0; i < n; i++)
	{
		if (i <= 1)
		{
			printf("%d", i);
		}
		else
		{
			next = first + second;
			printf("%d", next);
			first = second;
			second = next;
		}
		printf("\n");
	}
	return (0);
}
