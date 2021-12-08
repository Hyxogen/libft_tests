#include <stdio.h>
#include <ctype.h>

int	ft_isspace(int c);

int
	test_isspace()
{
	int	index;

	index = -256;
	while (index < 256) {
		if (ft_isspace(index) != isspace(index))
		{
			printf("Failed test ft_isspace. Expected:%d, got:%d for:%c(%d)\n", isspace(index), ft_isspace(index), index, index);
			return (0);
		}
		index++;
	}
	return (1);
}
