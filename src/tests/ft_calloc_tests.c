#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	*ft_calloc(size_t count, size_t size);

static int
	test_single(size_t count, size_t size)
{
	void	*tret;
	void	*cret;

	tret = ft_calloc(count, size);
	cret = calloc(count, size);
	if (memcmp(tret, cret, size * count))
	{
		printf("Failed test_single. Expected:0 got:%d\n", memcmp(tret, cret, size * count));
		return (0);
	}
	memset(tret, 0xFF, count * size);
	memset(cret, 0xFF, count * size);
	free(tret);
	free(cret);
	return (1);
}

static int
	test_empty()
{
	if (!test_single(10, 0))
	{
		printf("At test_empty. test_single(10, 0)\n\n");
		return (0);
	}
	if (!test_single(0, 10))
	{
		printf("At test_empty. test_single(0, 10)\n\n");
		return (0);
	}
	if (!test_single(0, 0))
	{
		printf("At test_empty. test_single(0, 0)\n\n");
		return (0);
	}
	return (1);
}

static int
	test_full()
{
	if (!test_single(500, 80))
	{
		printf("At test_full.\n\n");
		return (0);
	}
	return (1);
}

int
	test_calloc()
{
	int	ret;

	ret = 1;
	if (!test_empty())
		ret = 0;
	if (!test_full())
		ret = 0;
	return (ret);
}
