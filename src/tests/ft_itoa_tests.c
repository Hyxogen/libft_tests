#include <string.h>
#include "../../libft.h"

typedef struct s_test_pair {
	int		m_test_num;
	char	*m_corr_str;
}			t_test_pair;

const static t_test_pair g_tests[] = {
	{0, "0"},
	{42, "42"},
	{-42, "-42"},
	{-128, "-128"},
	{128, "128"},
	{128, "128"},
	{255, "255"},
	{256, "256"},
	{-32768, "-32768"},
	{32768, "32768"},
	{65535, "65535"},
	{-2147483648, "-2147483648"},
	{2147483647, "2147483647"},
	{0, 0}
};

static int
	test_single(const t_test_pair* test_pair)
{
	const char	*tret;

	tret = ft_itoa(test_pair->m_test_num);
	if (strcmp(tret, test_pair->m_corr_str))
	{
		printf("Failed test_single for ft_itoa.\nExpected:\n\"%s\"\nGot:\n\"%s\"\n", test_pair->m_corr_str, tret);
		return (0);
	}
	return (1);
}

static int
	test_all()
{
	int	index;

	index = 0;
	while (g_tests[index].m_corr_str)
	{
		if (!test_single(&g_tests[index]))
		{
			printf("At test_all. index:%d\n\n", index);
			return (0);
		}
		index++;
	}
	return (1);
}

int
	test_itoa()
{
	int	ret;

	ret = 1;
	if (!test_all())
		ret = 0;
	return (ret);
}
