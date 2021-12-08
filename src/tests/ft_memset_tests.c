#include <string.h>
#include <stdio.h>

void	*ft_memset(void *dest, int ch, size_t len);

static int
	test_nulldest()
{
	char	*ctemp;
	char	*ttemp;

	ctemp = memset(0, 0, 0);
	ttemp = ft_memset(0, 0, 0);
	return (1);
}

static int
	test_fill_zero_s()
{
	char	ctemp[100];
	char	ttemp[100];
	void*	tret;
	int		index;
	int		diff;

	//TODO check if return value is correct
	index = 0;
	while (index < 100)
	{
		memset(ctemp, 0, index);
		tret =ft_memset(ttemp, 0, index);
		diff = memcmp(ctemp, ttemp, index);
		if (diff)
		{
			printf("Failed test_fill_zero_s. Expected: 0 got: %d at index:%d\n", diff, index);
			return (0);
		}
		if (tret != &ttemp[0])
		{
			printf("Failed test_fill_zero_s. Expected return value: %lx, got: %lx at index:%d\n", (unsigned long) &ttemp[0], (unsigned long) tret, index);
			return (0);
		}
		index++;
	}
	return (1);
}

static int
	test_fill_all_v()
{
	char	ctemp[100];
	char	ttemp[100];
	void*	tret;
	int		index;
	int		val;

	index = 0;
	while (index < 100)
	{
		val = -256;
		while (val < 256)
		{
			memset(ctemp, val, index);
			tret = ft_memset(ttemp, val, index);
			if (memcmp(ctemp, ttemp, index))
			{
				printf("Failed test_fill_all_v. Expected: 1, got: 0 at index:%d, val:%d\n", index, val);
				return (0);
			}
			if (tret != &ttemp[0])
			{
				printf("Failed test_fill_all_v. Expected return value: %lx, got: %lx at index:%d\n", (unsigned long) &ttemp[0], (unsigned long) tret, index);
				return (0);
			}
			val++;
		}
		index++;
	}
	return (1);
}

int
	test_memset()
{
	int ret;
	char buffer[10];

	memset(&buffer[0], 0xFF, 3);
	ft_memset(&buffer[0], 0, 3);
//	return (0);
	ret = 1;
	if (!test_nulldest())
		ret = 0;
	if (!test_fill_zero_s())
		ret = 0;
	if (!test_fill_all_v())
		ret = 0;
	return (ret);
}
