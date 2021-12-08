#include <stdio.h>
#include <string.h>
#include "../../libft.h"

typedef struct s_test {
	char			*m_test_str1;
	char			*m_test_str2;
	char			*m_corr_str;
}					t_test;

const static t_test g_pairs[] = {
	{"Hallo", "", "Hallo"},
	{"XYZHalloZYX", "XYZ", "Hallo"},
	{"     Hallo    ", " ", "Hallo"},
	{"Hallo", "Ho", "all"},
	{0, 0, 0},
};

static int
	test_single(const t_test *test)
{
	char	*ret_str;

	ret_str = ft_strtrim(test->m_test_str1, test->m_test_str2);
	if (ret_str == 0 && test->m_corr_str == 0)
		return (1);
	if (strcmp(ret_str, test->m_corr_str))
	{
		printf("Failed test_single for ft_strtrim. Expected:\n\"%s\"\ngot:\"\n%s\"\n", test->m_corr_str, ret_str);
		return (0);
	}
	return (1);
}

static int
	test_all()
{
	int	index;

	index = 0;
	while (g_pairs[index].m_test_str1)
	{
		if (!test_single(&g_pairs[index]))
		{
			printf("At test_all. index:%d\n\n", index);
			return (0);
		}
		index++;
	}
	return (1);
}

int
	test_strtrim()
{
	int	ret;

	ret = 1;
	if (!test_all())
		ret = 0;
	return (ret);
}
