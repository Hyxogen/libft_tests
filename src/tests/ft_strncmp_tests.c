#include <stdio.h>
#include <string.h>

const static char	*strs[] = {
	"Hallo, dit is een string!",
	"Hallo, dit is een string?!",
	"Hallo dit is een string",
	"a",
	"b",
	"h",
	"Lorem ipsum dolor sit amet, consectetur adipiscing elit.",
	"Morbi posuere velit vitae mi blandit sagittis.",
	"Nullam lobortis magna ac euismod pellentesque.",
	"Nam volutpat lacus posuere, viverra odio sed, porta metus.",
	"",
	"lorem ipsum dolor sit amet",
	"Hallo, lobortis magna ac euismod pellentesque."
	"L",
	"\xFF"
	"\n",
	0
};

int	ft_strncmp(const char *s1, const char *s2, size_t n);

static int
	test_single(const char *s1, const char *s2, size_t n)
{
	if (ft_strncmp(s1, s2, n) != strncmp(s1, s2, n))
	{
		printf("Failed test_single for ft_strncmp. Expected:%d got:%d\n", strncmp(s1, s2, n), ft_strncmp(s1, s2, n));
		return (0);
	}
	return (1);
}

static int
	test_all()
{
	int	index_first;
	int	index_second;
	size_t flen;
	size_t n;

	index_first = 0;
	while (strs[index_first])
	{
		index_second = 0;
		flen = strlen(strs[index_first]);
		while (strs[index_second])
		{
			n = 0;
			while (n <= flen)
			{
				if (!test_single(strs[index_first], strs[index_second], n))
				{
					printf("At test_all for ft_strncmp. s1:%s s2:%s n:%zu\n\n", strs[index_first], strs[index_second], n);
					return (0);
				}
				n++;
			}
			index_second++;
		}
		index_first++;
	}
	return (1);
}

static int
	test_bigger()
{
	int	index_first;
	int	index_second;
	size_t flen;
	size_t n;

	index_first = 0;
	while (strs[index_first])
	{
		index_second = 0;
		flen = strlen(strs[index_first]);
		while (strs[index_second])
		{
			n = flen;
			while (n <= (flen * 1000))
			{
				if (!test_single(strs[index_first], strs[index_second], n))
				{
					printf("At test_bigger for ft_strncmp. s1:%s s2:%s n:%zu\n\n", strs[index_first], strs[index_second], n);
					return (0);
				}
				n++;
			}
			index_second++;
		}
		index_first++;
	}
	return (1);
}

static int
	test_custom()
{
	if (!test_single("lorem ipsum dolor sit amet", "ipsumm", 30))
		return (0);
	if (!test_single("lorem ipsum dolor sit amet", "consectetur", 30))
		return (0);
	return (1);
}

//TODO test for big n (lile UINT_MAX)
int
	test_strncmp()
{
	int	ret;

	ret = 1;
	if (!test_all())
		ret = 0;
	if (!test_bigger())
		ret = 0;
	if (!test_custom())
		ret = 0;
	return (ret);
}
