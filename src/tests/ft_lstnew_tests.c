#include "../../libft.h"

static int
	test_simple()
{
	t_list	*test;
	int			content;

	content = 42;
	test = ft_lstnew(&content);
	if (test->content != &content)
	{
		printf("Test failed for ft_lstnew. Invalid pointer\n");
		return (0);
	}
	if (*((int*)test->content) != content)
	{
		printf("Test failed for ft_lstnew. Not the same data!\n");
		return (0);
	}
	return (1);
}

static int
	test_null()
{
	t_list *test;

	test = ft_lstnew(0);
	if (test->content != 0)
	{
		printf("Test failed for ft_lstnew. Passing null didn't work!\n");
		return (0);
	}
	return (1);
}

int
	test_lstnew()
{
	int ret;

	ret = 1;
	if (!test_simple())
		ret = 0;
	if (!test_null())
		ret = 0;
	return (ret);
}
