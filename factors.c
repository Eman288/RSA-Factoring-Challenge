#include "main.h"

/**
 * main - the main fuction to start the code
 * @argc: the number of arguments passed to the program
 * @argv: the array of chars of the arguments
 * Return: 0 on success
 */
int main (int argc, char *argv[])
{
	int i, j, flag = 1, k = 0;

	long ll, primes[5133];

	FILE *fd;

	char *buff = NULL;

	size_t n;
	if (argc < 2 || argc > 2)
	{
		printf("error");
		return (-1);
	}
	for (i = 2; i < 50000; i++)
	{
		for (j = 2; j <= i / 2; j++)
		{
			if (i % j == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			primes[k] = i;
			k++;
		}
		flag = 1;
	}
	fd = fopen(argv[1], "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buff, &n, fd) != -1)
	{
		ll = strtol(buff, NULL, 10);
		for (i = 0; i < 5133; i++)
		{
			if (ll % primes[i] == 0)
			{
				printf("%ld=%ld*%ld\n", ll, ll / primes[i], primes[i]);
				break;
			}
		}
	}
	free(buff);
	fclose(fd);
	return (0);
}
