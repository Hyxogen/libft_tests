#include <stdio.h>
#include <ctype.h>

int	ft_isprint(int c);

int
	test_isprint()
{
	int c;

	c = -256;
	while (c < 256)
	{
		if (ft_isprint(c) != isprint(c))
		{
			printf("Failed test ft_isprint. Expected:%d, got:%d for:%c(%d)\n", isprint(c), ft_isprint(c), c, c);
			return (0);
		}
		c++;
	}
	return (1);
}