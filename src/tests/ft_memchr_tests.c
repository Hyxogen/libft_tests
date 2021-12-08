#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n);

static int
	test_single(const void *s, int c, size_t n)
{
	if (ft_memchr(s, c, n) != memchr(s, c, n))
	{
		printf("Failed test_single for ft_memchr. Expected:%lx got:%lx\n", (unsigned long) memchr(s, c, n), (unsigned long) ft_memchr(s, c, n));
		return (0);
	}
	return (1);
}

//For a specific n
static int
	test_all_an(const void *buf, size_t n)
{
	const unsigned char	*arr;
	int				val;

	arr = buf;
	val = 0;
	while (val < 256)
	{
		if (!test_single(buf, val, n))
		{
			printf("At test_all_an. Val:%d\n", val);
			return (0);
		}
		val++;
	}
	return (1);
}

//Up to n
static int
	test_all_a(const void *buf, size_t n)
{
	while (n)
	{
		if (!test_all_an(buf, n))
		{
			printf("At test_all_a. n:%zu\n", n);
			return (0);
		}
		n--;
	}
	return (1);
}

static int
	test_no_find()
{
	unsigned char	buf[256];
	int				index;
	int				missing;

	missing = 0;
	while (missing < 256)
	{
		index = 0;
		while (index < 256)
		{
			if((index + 1) == missing)
				buf[index] = (missing + 1) % 256;
			else
				buf[index] = (index + 1) % 256;
			index++;
		}
		if (!test_all_a(buf, 256))
		{
			printf("At test_no_find. Missing:%d\n\n", missing);
			return (0);
		}
		missing++;
	}
	return (1);
}

static int
	test_duplicates()
{
	unsigned char	buf[256 * 2];
	int				index;
	int				counter;

	index = 0;
	counter = 0;
	while (index < 256)
	{
		buf[index] = (counter + 1) % 256;
		buf[index + 1] = (counter + 1) % 256;
		counter++;
		index += 2;
	}
	if (!test_all_a(buf, 256))
	{
		printf("At test_duplicates.\n\n");
		return (0);
	}
	return (1);
}

static int
	test_all()
{
	unsigned char	buf[256];
	int				index;

	index = 0;
	while (index < 256)
	{
		buf[index] = (unsigned char) ((index + 1) % 256);
		index++;
	}

	if (!test_all_a(buf, 256))
	{
		printf("At test_all.\n\n");
		return (0);
	}
	return (1);
}

int
	test_memchr()
{
	int	ret;

	ret = 1;
	if (!test_all())
		ret = 0;
	if (!test_no_find())
		ret = 0;
	if (!test_duplicates())
		ret = 0;
	return (ret);
}
