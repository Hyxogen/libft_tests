#include <stdio.h>
#include <ctype.h>

int	ft_isalpha(int c);

int
	test_isalpha()
{
	int	c;

	c = -256;
	while (c < 265)
	{
		if (ft_isalpha(c) != isalpha(c))
		{
			printf("Failed test ft_isalpha. Expected:%d, got:%d for:%d\n", isalpha(c), ft_isalpha(c), c);
			return (0);
		}
		c++;
	}
	return (1);
}