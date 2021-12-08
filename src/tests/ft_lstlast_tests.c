#include "../../libft.h"

static int
	test_mult_sizes()
{
	t_list	*ret;
	t_list	*elem1, *elem2, *elem3, *elem4, *elem5;

	elem1 = ft_lstnew("elem1");
	ret = ft_lstlast(elem1);
	if (ret != elem1)
	{
		printf("Failed test_mult_sizes for ft_lstlast. Expected:%p got:%p\n", (void*) elem1, (void*) ret);
		return (0);
	}
	elem2 = ft_lstnew("elem2");
	elem1->next = elem2;
	ret = ft_lstlast(elem1);
	if (ret != elem2)
	{
		printf("Failed test_mult_sizes for ft_lstlast. Expected:%p got:%p\n", (void*)elem2, (void*) ret);
		return (0);
	}
	elem3 = ft_lstnew("elem3");
	elem2->next = elem3;
	ret = ft_lstlast(elem1);
	if (ret != elem3)
	{
		printf("Failed test_mult_sizes for ft_lstlast. Expected:%p got:%p\n", (void*) elem3, (void*) ret);
		return (0);
	}
	elem4 = ft_lstnew("elem4");
	elem3->next = elem4;
	ret = ft_lstlast(elem1);
	if (ret != elem4)
	{
		printf("Failed test_mult_sizes for ft_lstlast. Expected:%p got:%p\n", (void*) elem4, (void*) ret);
		return (0);
	}
	elem5 = ft_lstnew("elem5");
	elem4->next = elem5;
	ret = ft_lstlast(elem1);
	if (ret != elem5)
	{
		printf("Failed test_mult_sizes for ft_lstlast. Expected:%p got:%p\n", (void*) elem5, (void*) ret);
		return (0);
	}
	return (1);
}

int
	test_lstlast()
{
	int	ret;

	ret = 1;
	if (!test_mult_sizes())
		ret = 0;
	return (ret);
}
