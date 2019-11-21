#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

int main()
{
	int i = INT_MIN;

	while (i < INT_MAX)
	{
		if (i != ft_atoi_base(itoa(i), "0123456789", 10))
			printf("%d", i);
	}
}
