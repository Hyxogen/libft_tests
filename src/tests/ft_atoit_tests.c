#include <stdio.h>
#include <stdlib.h>

const static char	*test_strs[] = {
	"0",
	"05",
	"042",
	"42",
	"24",
	"-42",
	"-24",
	"+42",
	"+24",
	"--42",
	"--24",
	"++42",
	"++24",
	"-+42",
	"-+24",
	"+-42",
	"+-24",
	"2147483647",
	"2147483648",
	"-2147483648",
	"-0",
	"0",
	"42",
	"24",
	"- 42",
	"-24",
	" +42",
	"+24",
	"--4 2",
	"--2 4",
	"++4 2",
	"++2 4",
	"-+4 2",
	"-+2 4",
	"+-4 2",
	"+-2 4",
	"21474 83647",
	"21474 83648",
	"-2147 483648",
	"42949 67295",
	"-4294 967295",
	"-0000000000000000000000004294 967295",
	"     \t\v\f\t\r92233720368\t 4775807",
	"     \t\v\f\t\r92233720368\t 4775808",
	"     \t\v\f\t\r+9223372036\t 54775808",
	"     \t\v\f\t\r-9223372036\t 54775808",
	"     \t\v\f\t\r-9223372036\t 54775807",
	"     \t\v\f\t\r18446744073\t 09551615",
	"     \t\v\f\t\r18446744073\t 09551616",
	"     \t\v\f\t\r-1844674407\t 709551615",
	"     \t\v\f\t\r-1844674407\t 709551616",
	"     \t\v\f\t\r19446744073\t 09551616",
	"     \t\v\f\t\r-0\t4",
	0
};

int	ft_atoi(const char *str);

static int
	test_single(const char *str)
{
	int	tret;
	int	cret;

	tret = ft_atoi(str);
	cret = atoi(str);
	if (tret != cret)
	{
		printf("Failed test_single for ft_atoi. Expected:%d got:%d for:%s\n", cret, tret, str);
		return (0);
	}
	return (1);
}

static int
	test_all()
{
	int	index;

	index = 0;
	while (test_strs[index])
	{
		if (!test_single(test_strs[index]))
		{
			printf("At test_all. index:%d\n", index);
			return (0);
		}
		index++;
	}
	return (1);
}

int
	test_atoi()
{
	int	ret;

	ret = 1;
	if (!test_all())
		ret = 0;
	return (ret);
}
