#include<stdio.h>
#include<math.h>

int main(void)
{
	float x;
	float g = 0.0;
	int count = 0;
	while (scanf("%f", &x) == 1)
	{
		count++;
		if (count = 1 && x < 0)
		{
			printf("Error");
			return -1;
		}
		g = sqrt(g) + x;
		if (g < 0)
		{
			printf("Error");
			return -1;
		}
	}
	g = sqrt(g);
	printf("%f", g);
	return 0;
}
