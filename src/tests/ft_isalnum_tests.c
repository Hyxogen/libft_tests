#include <stdio.h>
#include <ctype.h>

int	ft_isalnum(int c);

int
	test_isalnum()
{
	int	index;

	index = -256;
	while (index < 256) {
		if (ft_isalnum(index) != isalnum(index))
		{
			printf("Failed test ft_isalnum. Expected:%d, got:%d for:%c(%d)\n", isalnum(index), ft_isalnum(index), index, index);
			return (0);
		}
		index++;
	}
	return (1);
}
