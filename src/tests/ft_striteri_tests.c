#include <string.h>
#include "../../libft.h"

typedef struct s_test_pair {
	char	*test_str;
	char	*corr_str;
}				t_test_pair;

const static t_test_pair g_test_pairs[] = {
	{"Hallo!", "012345"},
	{"Hallo, dit is een string!", "0123456789012345678901234"},
	{0, 0}
};

static void
	test_func(unsigned int index, char *c)
{
	*c = '0' + (index % 10);
}

static int
	test_single(const t_test_pair *test_pair)
{
	char	*tret;

	tret = strdup(test_pair->test_str);
	ft_striteri(tret, &test_func);
	if (strcmp(tret, test_pair->corr_str))
	{
		printf("Failed test_single for ft_strmapi.\nExpected:\n\"%s\"\nGot:\n\"%s\"\n", test_pair->corr_str, tret);
		return (0);
	}
	return (1);
}

static int
	test_all()
{
	int	index;

	index = 0;
	while (g_test_pairs[index].test_str)
	{
		if (!test_single(&g_test_pairs[index]))
		{
			printf("At test_all. index:%d\n", index);
			return (0);
		}
		index++;
	}
	return (1);
}

int
	test_striteri()
{
	int	ret;

	ret = 1;
	if (!test_all())
		ret = 0;
	return (ret);
}

