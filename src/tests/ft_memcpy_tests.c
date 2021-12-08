#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n);

static int
	test_null()
{
	int	src[2024] = { 0, 4, 2, 1, 9, 8, 6, 5, 3, 7};
	int	dest[2024];

	ft_memcpy(0, 0, 2024);
	ft_memcpy(dest, src, 0);
	return (1);
}

static int
	test_filled()
{
	int	tsrc[2024];
	int	tdest[2024];
	int	csrc[2024];
	int	cdest[2024];
	int	val;

	val = -256;
	while (val < 256)
	{
		memset(tsrc, val, 2024 * sizeof(int));
		memset(csrc, val, 2024 * sizeof(int));

		ft_memcpy(tdest, tsrc, 2024 * sizeof(int));
		memcpy(cdest, tsrc, 2024 * sizeof(int));
		if (memcmp(tdest, cdest, 2024 * sizeof(int)))
		{
			printf("Failed test_filled. Expected: 1, got: 0 at val:%d\n", val);
			return (0);
		}
		val++;
	}
	return (1);
}

int
	test_memcpy()
{
	int	ret;

	ret = 1;
	if (!test_null())
		ret = 0;
	if (!test_filled())
		ret = 0;
	return (ret);
}
