#include<stdio.h>
#include<math.h>

int prime(int a)
{
	int count = 0;
	if (a < 2)
		return 0;
	if (a == 2)
		return 1;
	for (int i = 1; i <= a; i++)
	{
		if (a % i ==0)
			count += 1;
	}
	if (count == 2)
		return 1;
	else
		return 0;
}

int main(void)
{
	int a[1024];
	int n , rc, input, count = 0;
	rc = scanf("%d", &n);
	if (rc == 1 && n > 0)
	{
		for (int i = 0; i < n; i++)
		{
			if (scanf("%d", &input) == 1)
			{
				a[count++] = input;
				if (prime(input))
				{
					a[count++] = 0;
				}
			}
			else
			{
				printf("Input Error");
				return -1;
			}
		}
		for (int i = 0; i < count; i++)
		{
			printf("%d ", a[i]);
		}
	}
	else
	{
		printf("Input error");
		return -1;
	}
	return 0;
}