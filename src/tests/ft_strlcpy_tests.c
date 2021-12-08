#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const static char 	*test_srcs[] = {
	"Hallo dit is een string",
	"Hallo",
	" string",
	" ",
	"\n",
	"",
	"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec non dictum mauris, eu dignissim turpis. Maecenas lorem justo, suscipit nec nisl non, placerat porttitor velit. Aenean cursus nibh nec porttitor rhoncus. Sed malesuada, arcu quis malesuada dictum, arcu metus interdum odio, in condimentum eros erat eget enim. Donec ultricies ante quam, in vulputate orci imperdiet at. Nam pellentesque, ex quis bibendum lacinia, arcu libero porttitor tellus, id bibendum magna tortor ut felis. In fringilla vel est ac hendrerit. Sed eget congue nisl. Nullam nec tellus id enim lacinia ultricies fermentum tincidunt metus. Vestibulum et nibh volutpat dui auctor rutrum at pretium turpis. Nulla a lacinia enim, sit amet sagittis massa. Quisque congue turpis vel ipsum elementum, eu semper diam vestibulum. Etiam rhoncus mauris ut fermentum vestibulum. Proin bibendum lectus sem. Suspendisse sed turpis et orci gravida commodo sed eget ante. Integer ut egestas purus. Nunc odio erat, maximus quis tristique non, faucibus sit amet tellus. Nullam nec auctor magna, quis facilisis magna. Sed a felis nec augue pharetra tempus quis in neque. Vestibulum magna ligula, luctus a tortor ac, scelerisque semper ex. Aliquam tortor augue, consequat ac egestas vel, molestie et turpis. Aliquam id eros consectetur, venenatis ipsum sit amet, aliquet sapien. Morbi eleifend justo a est elementum, at scelerisque sem interdum. Sed varius mauris sed lorem rutrum, in rhoncus sapien tempus. Donec iaculis gravida orci, ac elementum enim lacinia efficitur. Ut nec neque a nisi luctus bibendum ut vitae turpis. Proin non neque tincidunt, laoreet odio at, condimentum leo. Curabitur finibus risus ac turpis rhoncus, quis elementum arcu condimentum. Aliquam tortor augue, feugiat sed elementum ac, consectetur ut orci. Cras ornare lacus mauris. Suspendisse sed condimentum magna. Donec ultrices ante massa, eu bibendum sem placerat eget. Donec imperdiet elit quis leo lacinia, at accumsan ante tincidunt. Donec volutpat ac quam eu vulputate. Vivamus porta justo sit amet purus consequat lobortis et posuere velit. In hac habitasse platea dictumst. Suspendisse venenatis luctus quam, vitae lobortis leo convallis tristique. Sed in velit semper, imperdiet erat vel, malesuada sapien. Quisque in nisl libero. Sed vestibulum elit ac tortor tincidunt commodo. Nam nec lorem ullamcorper, congue odio ut, pulvinar metus. Morbi fringilla congue nibh a pretium. Proin sodales mi non sem rhoncus condimentum. Morbi faucibus auctor neque sed facilisis. Curabitur gravida elementum augue a tristique. Vivamus sit amet nulla commodo, sodales mauris a, blandit nisl. Donec eget mauris mollis mi laoreet tristique. Quisque condimentum diam quis consectetur convallis. Maecenas mi urna, fringilla a velit in, tempor tempus libero. Phasellus gravida, nunc a luctus auctor, justo velit interdum urna, eu porttitor urna quam eget metus. Pellentesque non ante eget nisi aliquet ullamcorper. Fusce mollis eget orci ut iaculis. Nunc vitae tristique urna. Cras mauris quam, volutpat non ipsum et, ultricies scelerisque erat. Aliquam erat volutpat. Nulla libero lacus, pulvinar et iaculis nec, varius et urna. Proin lorem ante, posuere vel magna sed, placerat pellentesque odio.",
	0
};

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

static int
	test_single(const char *tsrc, size_t tsize)
{
	char	*tdst;
	char	*cdst;
	size_t	cret;
	size_t	tret;
	
	tdst = malloc(tsize);
	cdst = malloc(tsize);
	memset(tdst, 0xFF, tsize);
	memset(cdst, 0xFF, tsize);
	tret = ft_strlcpy(tdst, tsrc, tsize);
	cret = strlcpy(cdst, tsrc, tsize);
	if (tret != cret)
	{
		printf("Failed test_single for ft_strlcpy! Expected return:%zu got:%zu\n", cret, tret);
		return (0);
	}
	if (memcmp(tdst, cdst, tsize))
	{
		printf("Failed test_single for ft_strlcpy!\nExpected:\n%s\nGot:\n%s\n", cdst, tdst);
		return (0);
	}
	return (1);
}

static int
	test_insufficient()
{
	size_t		src_index;
	size_t		index;
	size_t		srclen;
	const char	*temp;

	src_index = 0;
	while (test_srcs[src_index])
	{
		temp = test_srcs[src_index];
		srclen = strlen(temp);
		index = 0;
		while (index <= srclen)
		{
			if (!test_single(temp, index))
			{
				printf("At test_insufficinent for ft_strlcpy. At src_index:%zu index:%zu\n\n", src_index, index);
				return (0);
			}
			index++;
		}
		src_index++;
	}
	return (1);
}

static int
	test_segfaults()
{
	char	*src = "Hallo";
	return (test_single(src, 1024 * 100000));
}

static int
	test_normal()
{
	size_t		src_index;
	const char	*temp;

	src_index = 0;
	while (test_srcs[src_index])
	{
		temp = test_srcs[src_index];
		if (!test_single(temp, strlen(temp)))
		{
			printf("At test_normal for ft_strlcpy. At src_index:%zu\n\n", src_index);
			return (0);
		}
		src_index++;
	}
	return (1);
}

int
	test_strlcpy()
{
	int	ret;

	ret = 1;
	if (!test_insufficient())
		ret = 0;
	if (!test_segfaults())
		ret = 0;
	if (!test_normal())
		ret = 0;
	return (ret);
}
