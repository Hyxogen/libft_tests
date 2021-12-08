#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n);

static int
	test_single(const void *s1, const void *s2, size_t n)
{
	if (ft_memcmp(s1, s2, n) != memcmp(s1, s2, n))
	{
		printf("Failed test_single for ft_memcmp. Expected:%d got:%d\n", memcmp(s1, s2, n), ft_memcmp(s1 , s2, n));
		return (0);
	}
	return (1);
}

//Tests for all values of n of ft_memcmp up to n
static int
	test_all_a(const void *s1, const void *s2, size_t n)
{
	while (n)
	{
		if (!test_single(s1, s2, n))
		{
			printf("At test_all_a. n:%zu\n", n);
			return (0);
		}
		n--;
	}
	return (1);
}

static int
	test_equals()
{
	unsigned char	buf1[256];
	unsigned char	buf2[256];
	int				index;

	index = 0;
	while (index < 256)
	{
		buf1[index] = (unsigned char) ((index + 1) % 256);
		index++;
	}
	memcpy(&buf2[0], &buf1[0], 256);

	if (!test_all_a(&buf1[0], &buf1[0], 256))
	{
		printf("At test_equals with same pointer\n\n");
		return (0);
	}
	if (!test_all_a(&buf1[0], &buf2[0], 256))
	{
		printf("At test_equals with diffrent pointer\n\n");
		return (0);
	}
	return (1);
}

static int
	test_shifted()
{
	unsigned char	buf1[256];
	unsigned char	buf2[256];
	int				index;
	int				shift;

	shift = 0;
	while (shift < 256)
	{
		index = 0;
		while (index < 256)
		{
			buf1[index] = (unsigned char) ((index + 1) % 256);
			buf2[index] = (unsigned char) ((index + shift + 1) % 256);
			index++;
		}
		if (!test_all_a(&buf1[0], &buf2[0], 256))
		{
			printf("At test_shifted. shift:%d\n\n", shift);
			return (0);
		}
		shift++;
	}
	return (1);
}

int
	test_memcmp()
{
	int	ret;

	ret = 1;
	if (!test_equals())
		ret = 0;
	if (!test_shifted())
		ret = 0;
	return (ret);
}
