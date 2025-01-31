#include <stdio.h>

/**
 * is_prime - checks if a number is prime
 * @n: the number to check
 * Return: 1 if n is prime, 0 otherwise
 */
int is_prime(int n)
{
	int i;

	if (n <= 1)
		return (0);

	for (i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return (0);
	}

	return (1);
}

/**
 * main - Entry point
 * Return: Always 0
 */
int main(void)
{
	int number = 29;

	if (is_prime(number))
		printf("%d is a prime number.\n", number);
	else
		printf("%d is not a prime number.\n", number);

	return (0);
}

