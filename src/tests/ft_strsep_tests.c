#include <string.h>
#include "../../libft.h"

const static char 	*test_strs[] = {
	"Hallo dit is een string",
	"Hallo",
	" string",
	" ",
	"\n",
	"",
	"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec non dictum mauris, eu dignissim turpis. Maecenas lorem justo, suscipit nec nisl non, placerat porttitor velit. Aenean cursus nibh nec porttitor rhoncus. Sed malesuada, arcu quis malesuada dictum, arcu metus interdum odio, in condimentum eros erat eget enim. Donec ultricies ante quam, in vulputate orci imperdiet at. Nam pellentesque, ex quis bibendum lacinia, arcu libero porttitor tellus, id bibendum magna tortor ut felis. In fringilla vel est ac hendrerit. Sed eget congue nisl. Nullam nec tellus id enim lacinia ultricies fermentum tincidunt metus. Vestibulum et nibh volutpat dui auctor rutrum at pretium turpis. Nulla a lacinia enim, sit amet sagittis massa. Quisque congue turpis vel ipsum elementum, eu semper diam vestibulum. Etiam rhoncus mauris ut fermentum vestibulum. Proin bibendum lectus sem. Suspendisse sed turpis et orci gravida commodo sed eget ante. Integer ut egestas purus. Nunc odio erat, maximus quis tristique non, faucibus sit amet tellus. Nullam nec auctor magna, quis facilisis magna. Sed a felis nec augue pharetra tempus quis in neque. Vestibulum magna ligula, luctus a tortor ac, scelerisque semper ex. Aliquam tortor augue, consequat ac egestas vel, molestie et turpis. Aliquam id eros consectetur, venenatis ipsum sit amet, aliquet sapien. Morbi eleifend justo a est elementum, at scelerisque sem interdum. Sed varius mauris sed lorem rutrum, in rhoncus sapien tempus. Donec iaculis gravida orci, ac elementum enim lacinia efficitur. Ut nec neque a nisi luctus bibendum ut vitae turpis. Proin non neque tincidunt, laoreet odio at, condimentum leo. Curabitur finibus risus ac turpis rhoncus, quis elementum arcu condimentum. Aliquam tortor augue, feugiat sed elementum ac, consectetur ut orci. Cras ornare lacus mauris. Suspendisse sed condimentum magna. Donec ultrices ante massa, eu bibendum sem placerat eget. Donec imperdiet elit quis leo lacinia, at accumsan ante tincidunt. Donec volutpat ac quam eu vulputate. Vivamus porta justo sit amet purus consequat lobortis et posuere velit. In hac habitasse platea dictumst. Suspendisse venenatis luctus quam, vitae lobortis leo convallis tristique. Sed in velit semper, imperdiet erat vel, malesuada sapien. Quisque in nisl libero. Sed vestibulum elit ac tortor tincidunt commodo. Nam nec lorem ullamcorper, congue odio ut, pulvinar metus. Morbi fringilla congue nibh a pretium. Proin sodales mi non sem rhoncus condimentum. Morbi faucibus auctor neque sed facilisis. Curabitur gravida elementum augue a tristique. Vivamus sit amet nulla commodo, sodales mauris a, blandit nisl. Donec eget mauris mollis mi laoreet tristique. Quisque condimentum diam quis consectetur convallis. Maecenas mi urna, fringilla a velit in, tempor tempus libero. Phasellus gravida, nunc a luctus auctor, justo velit interdum urna, eu porttitor urna quam eget metus. Pellentesque non ante eget nisi aliquet ullamcorper. Fusce mollis eget orci ut iaculis. Nunc vitae tristique urna. Cras mauris quam, volutpat non ipsum et, ultricies scelerisque erat. Aliquam erat volutpat. Nulla libero lacus, pulvinar et iaculis nec, varius et urna. Proin lorem ante, posuere vel magna sed, placerat pellentesque odio.",
	0
};

const static char	*test_delims[] = {
	" ",
	"abc",
	"abcdefghijklmnopqrstuvwxyz01234567890 \n\t\r\v\f",
	"",
	0
};

static int
	test_next_single(char **str, const char *delim)
{
	char	tbuffer[4048];
	char	*tpointer;
	char	*tret;
	char	*cret;

	
	tpointer = &tbuffer[0];
	strcpy(tpointer, *str);
	tret = ft_strsep(&tpointer, delim);
	cret = strsep(str, delim);
	if (tret == 0 && cret == 0)
		return (1);
	if (strcmp(tret, cret))
	{
		printf("Failed test_next_single for ft_strsep. Expected return:\n%s\nGot:\n%s\n", cret, tret);
		return (0);
	}
	if (tpointer == 0 && *str == 0)
		return (1);
	if (strcmp(tpointer, *str))
	{
		printf("Failed test_next_single for ft_strsep. Expected:\n%s\nGot:\n%s\n", *str, tpointer);
		return (0);
	}
	return (1);
}

static int
	test_single(const char *const str, const char *delim)
{
	char	buffer[4048];
	char	*pointer;

	pointer = &buffer[0];
	strcpy(pointer, str);
	while (1)
	{
		if(!test_next_single(&pointer, delim))
		{
			printf("At test_single. buffer:%s\n", &buffer[0]);
			return (0);
		}
		if (!pointer)
			break;
	}
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
		while (test_delims[delim_index])
		{
			if (!test_single(test_strs[str_index], test_delims[delim_index]))
			{
				printf("At test_all. str_index:%d delim_index:%d\n\n", str_index, delim_index);
				return (0);
			}
			delim_index++;
		}
		str_index++;
	}
	return (1);
}

int
	test_strsep()
{
	int	ret;

	ret = 1;
	if (!test_all())
		ret = 0;
	return (ret);
}
