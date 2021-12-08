#include <string.h>
#include <stdio.h>

size_t	ft_strlen(const char *str);

int
	test_ftstrlen()
{
	char	*strs[] = {
		"Hallo",
		"Hallo dit is een string",
		"0",
		"342 134 134 ",
		" ",
		"\t",
		""
	};

	char **arr = &strs[0];

	while (1)
	{
		if (ft_strlen(*arr) != strlen(*arr))
		{
			printf("Failed test ft_strlen. Expected:%lu, got:%lu for:%s\n", strlen(*arr), ft_strlen(*arr), *arr);
			return (0);
		}
		if (*arr[0] == 0)
			break ;
		arr += 1;
	}
	return (1);
}