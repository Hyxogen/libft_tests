#include <string.h>
#include "../../libft.h"

const static char 	*test_strs[] = {
	"Hallo dit is een string",
	"\0aa\0bbb",
	"      split       this for   me  !       ",
	"Hallo",
	" string",
	" ",
	"\n",
	"",
	"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec non dictum mauris, eu dignissim turpis. Maecenas lorem justo, suscipit nec nisl non, placerat porttitor velit. Aenean cursus nibh nec porttitor rhoncus. Sed malesuada, arcu quis malesuada dictum, arcu metus interdum odio, in condimentum eros erat eget enim. Donec ultricies ante quam, in vulputate orci imperdiet at. Nam pellentesque, ex quis bibendum lacinia, arcu libero porttitor tellus, id bibendum magna tortor ut felis. In fringilla vel est ac hendrerit. Sed eget congue nisl. Nullam nec tellus id enim lacinia ultricies fermentum tincidunt metus. Vestibulum et nibh volutpat dui auctor rutrum at pretium turpis. Nulla a lacinia enim, sit amet sagittis massa. Quisque congue turpis vel ipsum elementum, eu semper diam vestibulum. Etiam rhoncus mauris ut fermentum vestibulum. Proin bibendum lectus sem. Suspendisse sed turpis et orci gravida commodo sed eget ante. Integer ut egestas purus. Nunc odio erat, maximus quis tristique non, faucibus sit amet tellus. Nullam nec auctor magna, quis facilisis magna. Sed a felis nec augue pharetra tempus quis in neque. Vestibulum magna ligula, luctus a tortor ac, scelerisque semper ex. Aliquam tortor augue, consequat ac egestas vel, molestie et turpis. Aliquam id eros consectetur, venenatis ipsum sit amet, aliquet sapien. Morbi eleifend justo a est elementum, at scelerisque sem interdum. Sed varius mauris sed lorem rutrum, in rhoncus sapien tempus. Donec iaculis gravida orci, ac elementum enim lacinia efficitur. Ut nec neque a nisi luctus bibendum ut vitae turpis. Proin non neque tincidunt, laoreet odio at, condimentum leo. Curabitur finibus risus ac turpis rhoncus, quis elementum arcu condimentum. Aliquam tortor augue, feugiat sed elementum ac, consectetur ut orci. Cras ornare lacus mauris. Suspendisse sed condimentum magna. Donec ultrices ante massa, eu bibendum sem placerat eget. Donec imperdiet elit quis leo lacinia, at accumsan ante tincidunt. Donec volutpat ac quam eu vulputate. Vivamus porta justo sit amet purus consequat lobortis et posuere velit. In hac habitasse platea dictumst. Suspendisse venenatis luctus quam, vitae lobortis leo convallis tristique. Sed in velit semper, imperdiet erat vel, malesuada sapien. Quisque in nisl libero. Sed vestibulum elit ac tortor tincidunt commodo. Nam nec lorem ullamcorper, congue odio ut, pulvinar metus. Morbi fringilla congue nibh a pretium. Proin sodales mi non sem rhoncus condimentum. Morbi faucibus auctor neque sed facilisis. Curabitur gravida elementum augue a tristique. Vivamus sit amet nulla commodo, sodales mauris a, blandit nisl. Donec eget mauris mollis mi laoreet tristique. Quisque condimentum diam quis consectetur convallis. Maecenas mi urna, fringilla a velit in, tempor tempus libero. Phasellus gravida, nunc a luctus auctor, justo velit interdum urna, eu porttitor urna quam eget metus. Pellentesque non ante eget nisi aliquet ullamcorper. Fusce mollis eget orci ut iaculis. Nunc vitae tristique urna. Cras mauris quam, volutpat non ipsum et, ultricies scelerisque erat. Aliquam erat volutpat. Nulla libero lacus, pulvinar et iaculis nec, varius et urna. Proin lorem ante, posuere vel magna sed, placerat pellentesque odio.",
	0
};

const static char	test_delims[] = {
	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
	' ',
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
	'\0'
};

int
	test_single(const char *str, char delim)
{
	char	buffer[4048];
	char	delim_string[2];
	char 	**test_split;
	char	**test_start;
	char	*corr_string;
	char	*token;

	corr_string = &buffer[0];
	test_split = ft_split(str, delim);
	test_start = test_split;
	delim_string[0] = delim;
	delim_string[1] = '\0';
	strcpy(corr_string, str);
	while (*test_split)
	{
		while (*corr_string && *corr_string == delim)
			corr_string++;
		token = strsep(&corr_string, delim_string);
		if (!*token)
			token = NULL;
		if (!token)
		{
			printf("Failed test_single for ft_split. Expected end of array got:%s\n", *test_split);
			return (0);
		}
		if (strcmp(*test_split, token))
		{
			printf("Failed test_single for ft_split.\nExpected:\n%s\nGot:\n%s\n", token, *test_split);
			return (0);
		}
		test_split++;
	}
	free(test_start);
	return (1);
}

static int
	test_all()
{
	int	str_index;
	int	delim_index;

	str_index = 0;
	while (test_strs[str_index])
	{
		delim_index = 0;
		while (1)
		{
			if (!test_single(test_strs[str_index], test_delims[delim_index]))
			{
				printf("At test_all. str_index:%d delim_index:%d\n\n", str_index, delim_index);
				return (0);
			}
			if (!test_delims[delim_index])
				break;
			delim_index++;
		}
		str_index++;
	}
	return (1);
}

static int
	test_segfault()
{
	if (!test_single("\0aa\0bbb", '\0'))
	{
		printf("At test_segfault.\n\n");
	}
	return (1);
}

int
	test_split()
{
	int ret;

	ret = 1;
	if (!test_all())
		ret = 0;
	if (!test_segfault())
		ret = 0;
	return (ret);
}
