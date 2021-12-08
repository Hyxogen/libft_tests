#include <stdio.h>
#include <ctype.h>

int	ft_tolower(int c);

static int
	test_single(int c)
{
	if (ft_tolower(c) != tolower(c))
	{
		printf("Failed test_single for ft_tolower. Expected return:%d got:%d\n", tolower(c), ft_tolower(c));
		return (0);
	}
	return (1);
}

static int
	test_all()
{
	int	c;

	c = -256;
	while (c <= 256)
	{
		if (!test_single(c))
			return (0);
		c++;
	}
	return (1);
}

int
	test_tolower()
{
	int	ret;

	ret = 1;
	if (!test_all())
		ret = 0;
	return (ret);
}