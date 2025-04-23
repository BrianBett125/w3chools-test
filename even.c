#include <stdio.h>
/**
 * main - entry point of the program
 * description: a program that displays even numbers
 * Return: always (0), success
 */
int main(void)
{
	int limit, i;

	printf("enter the limit\n");
	scanf("%d", &limit);
	printf("the even numbers upto %d are\n", limit);
	for (i = 2; i <= limit; i += 2)
	{
		printf("%d", i);
	}
	printf("\n"); /*for a cleaner output*/
	return (0);
}
