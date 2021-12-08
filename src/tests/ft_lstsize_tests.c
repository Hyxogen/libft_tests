#include "../../libft.h"

static int
	test_empty()
{
	int ret;

	ret = ft_lstsize(0);
	if (ret)
	{
		printf("Failed test_empty for ft_lstsize. Expected:0 got:%d\n", ret);
		return (0);
	}
	return (1);
}

static int
	test_one_len()
{
	t_list	*elem;
	int			ret;

	elem = ft_lstnew("aaaaa");
	ret = ft_lstsize(elem);
	if (ret != 1)
	{
		printf("Failed test_one_len for ft_lstsize. Expected: 1 got:%d\n", ret);
		return (0);
	}
	return (1);
}

static int
	test_other_len()
{
	int			len;
	t_list	*elem1, *elem2, *elem3, *elem4, *elem5;

	elem1 = ft_lstnew("elem1");
	len = ft_lstsize(elem1);
	if (len != 1)
	{
		printf("Failed test_other_len for ft_lstsize. Expected:1 got:%d\n", len);
		return (0);
	}
	elem2 = ft_lstnew("elem2");
	elem1->next = elem2;
	len = ft_lstsize(elem1);
	if (len != 2)
	{
		printf("Failed test_other_len for ft_lstsize. Expected:2 got:%d\n", len);
		return (0);
	}
	elem3 = ft_lstnew("elem3");
	elem2->next = elem3;
	len = ft_lstsize(elem1);
	if (len != 3)
	{
		printf("Failed test_other_len for ft_lstsize. Expected:3 got:%d\n", len);
		return (0);
	}
	elem4 = ft_lstnew("elem4");
	elem3->next = elem4;
	len = ft_lstsize(elem1);
	if (len != 4)
	{
		printf("Failed test_other_len for ft_lstsize. Expected:4 got:%d\n", len);
		return (0);
	}
	elem5 = ft_lstnew("elem5");
	elem4->next = elem5;
	len = ft_lstsize(elem1);
	if (len != 5)
	{
		printf("Failed test_other_len for ft_lstsize. Expected:5 got:%d\n", len);
		return (0);
	}
	free(elem1);
	free(elem2);
	free(elem3);
	free(elem4);
	free(elem5);
	return (1);
}

int
	test_lstsize()
{
	int	ret;

	ret = 1;
	if (!test_empty())
		ret = 0;
	if (!test_one_len())
		ret = 0;
	if (!test_other_len())
		ret = 0;
	return (ret);
}
