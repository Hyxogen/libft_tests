#include <stdio.h>
#include <string.h>

void	ft_bzero(void *dest, size_t len);

static int
	test_fill_zero_s()
{
	char	ctemp[100];
	char	ttemp[100];
	int		index;

	index = 0;
	while (index < 100)
	{
		bzero(ctemp, index);
		ft_bzero(ttemp, index);
		if (memcmp(ctemp, ttemp, index))
		{
			printf("Failed test_fill_zero_s. Expected: 1, got: 0 at index:%d\n", index);
			return (0);
		}
		index++;
	}
	return (1);
}

int
	test_bzero()
{
	int	ret;

	ret = 1;
	if (!test_fill_zero_s())
		ret = 0;
	return (ret);
}