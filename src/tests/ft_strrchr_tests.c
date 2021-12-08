#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *str, int c);
char	*ft_strchr(const char *str, int c);

static int
	test_single(const char *str, int c)
{
	if (ft_strrchr(str, c) != strrchr(str, c))
	{
		printf("Failed test_single for ft_strrchr. Expected:%lx got:%lx\n", (unsigned long) strrchr(str, c), (unsigned long) ft_strrchr(str, c));
		return (0);
	}
	return (1);
}

static int
	test_all_chars_a(char *buf)
{
	int	index;

	index = -256;
	while (index <= 256)
	{
		if (!test_single(buf, index))
		{
			printf("At test_all_chars_a for ft_strrchr. Index:%d char:%c\n", index, index);
			return (0);
		}
		index++;
	}
	return (1);
}

static int
	test_all_chars()
{
	char	buffer[256];
	int		index;

	index = 0;
	while (index <= 256) {
		buffer[index] = (char) ((index + 1) % 256);
		index++;
	}
	if (!test_all_chars_a(buffer))
	{
			printf("At test_all_chars for ft_strrchr.\n\n");
			return (0);
	}
	return (1);
}

//Possible segfault when missing NUL
static int
	test_no_find()
{
	char	buffer[256];
	int		index;
	int		missing;

	missing = 0;
	while (missing < 256)
	{
		index = 0;
		while (index < 256)
		{
			if ((index + 1) == missing)
				buffer[index] = (char) ((missing + 1) % 256);
			else
				buffer[index] = (char) ((index + 1) % 256);
			index++; 
		}
		if (!test_all_chars_a(buffer))
		{
			printf("At test_no_find for ft_strrchr. Missing:%d index:%d\n\n", missing, index);
			return (0);
		}
		missing++;
	}
	return (1);
}

static int
	test_duplicates()
{
	char	buffer[256 * 2];
	int		index;
	int		counter;

	index = 0;
	counter = 1;
	while (index <= 256) {
		buffer[index] = counter % 256;
		buffer[index + 1] = counter % 256;
		index += 2;
	}
	if (!test_all_chars_a(buffer))
	{
			printf("At test_duplicates for ft_strrchr.\n\n");
			return (0);
	}
	return (1);
}

int
	test_strrchr()
{
	int	ret;

	ret = 1;
	if (!test_all_chars())
		ret = 0;
	if (!test_no_find())
		ret = 0;
	if (!test_duplicates())
		ret = 0;
	return (ret);
}
