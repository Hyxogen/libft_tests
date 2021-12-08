#include <stdio.h>
#include <ctype.h>

int	ft_isdigit(int c);

int
	test_isdigit()
{
	int	index;

	index = -256;
	while (index < 256)
	{
		if (isdigit(index) != ft_isdigit(index))
		{
			printf("Failed test ft_isdigit. Expected:%d, got:%d for:%c(%d)\n", isdigit(index), ft_isdigit(index), index, index);
			return (0);
		}
		index++;
	}
	return (1);
}