#include <stdio.h>
/**
 * fibonacci_loop - function to print fibonacci series using a loop
 * @n: the number of terms
 * description - print all elements in fibonacci series
 * Return: nothing
 */
void fibonacci_loop(int n)
{
	int i, first = 0, second = 1, next;

	printf("fibonacci upto %d terms: \n", n);
	for (i = 0; i <= n; i++)
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
	}
	printf("\n");
}
/**
 * main - entry point of the program
 * Return: always (0) success
 */
int main(void)
{
int num;

printf("enter the number of terms: \n");
scanf("%d", &num);
printf("using loop: \n");
fibonacci_loop(num);
printf("\n");
return (0);
}
