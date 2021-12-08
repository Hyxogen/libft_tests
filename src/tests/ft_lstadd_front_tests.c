#include "../../libft.h"
#include <stdarg.h>
#include <sys/_types/_va_list.h>

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
	test_single_element_arr()
{
	t_list	**first;
	t_list	*elem1;
	t_list	*elem1_cpy;
	t_list	*elem2;
	char		*elem1_cont = "elem1";
	char		*elem2_cont = "elem2";

	elem1 = ft_lstnew(elem1_cont);
	elem1_cpy = elem1;
	elem2 = ft_lstnew(elem2_cont);
	first = &elem1;
	ft_lstadd_front(first, elem2);
	if (!check_order(*first, elem2, elem1_cpy, 0))
	{
		printf("Failed test_single_element_arr for ft_lstadd_front. Incorrect order\n");
		return (0);
	}
	return (1);
}

static int
	test_multi_element_arr()
{
	t_list	*elem1, *elem2, *elem3, *elem4, *elem_new;
	t_list	*elem1_cpy;

	elem1 = ft_lstnew(0);
	elem2 = ft_lstnew(0);
	elem3 = ft_lstnew(0);
	elem4 = ft_lstnew(0);
	elem_new = ft_lstnew(0);
	elem1_cpy = elem1;
	elem1->next = elem2;
	elem2->next = elem3;
	elem3->next = elem4;
	ft_lstadd_front(&elem1, elem_new);
	if (!check_order(elem_new, elem_new, elem1_cpy, elem2, elem3, elem4, (long long) 0))
	{
		printf("failed test_multi_element_arr for ft_lstadd_front. Incorrect order\n");
		return (0);
	}
	return (1);
}

int
	test_lstad_front()
{
	int ret;

	ret = 1;
	if (!test_single_element_arr())
		ret = 0;
	if (!test_multi_element_arr())
		ret = 0;
	return (ret);
}
