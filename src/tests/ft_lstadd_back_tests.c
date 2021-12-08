#include "../../libft.h"

static int
	check_order(const t_list *start, ...)
{
	va_list				args;
	const t_list	*current;

	va_start(args, start);
	while (1)
	{
		current = va_arg(args, void*);
		if (current != start)
		{
			va_end(args);
			return (0);
		}
		if (!current)
			break ;
		start = start->next;
	}
	va_end(args);
	return (1);
}

static int
	test_empty()
{
	t_list	*lst;
	t_list	*elem;

	elem = ft_lstnew(0);
	lst = 0;
	ft_lstadd_back(&lst, elem);
	if (lst != elem)
	{
		printf("Failed test_empty for ft_lstadd_back\n");
		return (0);
	}
	return (1);
}

static int
	test_other_sizes()
{
	t_list	*lst;
	t_list	*elem2, *elem3, *elem4;

	lst = ft_lstnew("first");
	elem2 = ft_lstnew("elem2");
	elem3 = ft_lstnew("elem3");
	elem4 = ft_lstnew("elem4");
	ft_lstadd_back(&lst, elem2);
	if (!check_order(lst, lst, elem2, 0))
	{
		printf("Failed test_other_sizes for ft_lstadd_back. Expected lst, elem2\n");
		return (0);
	}
	ft_lstadd_back(&lst, elem3);
	if (!check_order(lst, lst, elem2, elem3, 0))
	{
		printf("Failed test_other_sizes for ft_lstadd_back. Expected lst, elem2, elem3\n");
		return (0);
	}
	ft_lstadd_back(&lst, elem4);
	if (!check_order(lst, lst, elem2, elem3, elem4, 0))
	{
		printf("Failed test_other_sizes for ft_lstadd_back. Expected lst, elem2, elem3, elem4\n");
		return (0);
	}
	return (1);
}

int
	test_lstadd_back()
{
	int	ret;

	ret = 1;
	if (!test_empty())
		ret = 0;
	if (!test_other_sizes())
		ret = 0;
	return (ret);
}
