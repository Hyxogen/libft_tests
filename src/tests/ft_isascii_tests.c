#include <stdio.h>
#include <ctype.h>

int	ft_isascii(int c);

int
	test_isascii()
{
	int	c;

	c = -256;
	while (c < 256)
	{
		if (ft_isascii(c) != isascii(c))
		{
			printf("Failed test ft_isascii. Expected:%d, got:%d for:%c(%d)\n", ft_isascii(c), ft_isascii(c), c, c);
			return (0);
		}
		c++;
	}
	return (1);
}