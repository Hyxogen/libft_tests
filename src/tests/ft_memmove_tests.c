#include <stdio.h>
#include <string.h>
//TODO test dest and src being same

void	*ft_memmove(void *dest, const void *src, size_t len);

static int
	test_null()
{
	int	arr[2024];

	ft_memmove(0, 0, 0);
	ft_memmove(0, 0, 2024 * sizeof(int));
	ft_memmove(&arr[0], &arr[0], 0);
	return (1);
}

static int
	test_fill_no_overlap()
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

		ft_memmove(tdest, tsrc, 2024 * sizeof(int));
		memmove(cdest, tsrc, 2024 * sizeof(int));
		if (memcmp(tdest, cdest, 2024 * sizeof(int)))
		{
			printf("Failed test_fill_no_overlap. Expected: 1, got: 0 at val:%d\n", val);
			return (0);
		}
		val++;
	}
	return (1);
}

static int
	*fill_array(int *arr, int size)
{
	int	*start;

	start = arr;
	while (size)
	{
		*arr = size;
		size--;
		arr++;
	}
	return (start);
}

static int
	test_fill_overlap_forward()
{
	int	tarr[4048];
	int	carr[4048];
	int offset;

	offset = 0;
	while (offset <= 2024)
	{
		//printf("val:%d, offset:%d\n", val, offset);
		fill_array(tarr, 4048);
		fill_array(carr, 4048);

		ft_memmove(tarr + offset, tarr, 2024 * sizeof(int));
		memmove(carr + offset, carr, 2024 * sizeof(int));
		if (memcmp(carr, tarr, 4048 * sizeof(int)))
		{
			printf("Failed test_fill_overlap_forward. Expected: 0, got:%d at offset:%d\n", memcmp(carr, tarr, 4048 * sizeof(int)), offset);
			return (0);
		}
		offset++;
	}
	return (1);
}

static int
	test_fill_overlap_backward()
{
	int	tarr[4048];
	int	carr[4048];
	int offset;

	offset = 0;
	while (offset <= 2024)
	{
		fill_array(tarr, 4048);
		fill_array(carr, 4048);

		ft_memmove(tarr, tarr + offset, 2024 * sizeof(int));
		memmove(carr, carr + offset, 2024 * sizeof(int));
		if (memcmp(carr, tarr, 4048 * sizeof(int)))
		{
			printf("Failed test_fill_overlap_backward. Expected: 1, got: 0 at offset:%d\n", offset);
			return (0);
		}
		offset++;
	}
	return (1);
}

int
	test_memmove()
{
	int	ret;

	ret = 1;
	if (!test_null())
		ret = 0;
	if (!test_fill_no_overlap())
		ret = 0;
	if (!test_fill_overlap_forward())
		ret = 0;
	if (!test_fill_overlap_backward())
		ret = 0;
	return (ret);
}
