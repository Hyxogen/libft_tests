#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//These tests arent really good, since they don't check if strlcat might cause segfaults. Todo add tests with really big strings (like really big) to test for segfaults

const static char 	*test_dsts[] = {
	"Hallo dit is een string",
	"Hallo",
	" string",
	" ",
	"\n",
	"",
	"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec non dictum mauris, eu dignissim turpis. Maecenas lorem justo, suscipit nec nisl non, placerat porttitor velit. Aenean cursus nibh nec porttitor rhoncus. Sed malesuada, arcu quis malesuada dictum, arcu metus interdum odio, in condimentum eros erat eget enim. Donec ultricies ante quam, in vulputate orci imperdiet at. Nam pellentesque, ex quis bibendum lacinia, arcu libero porttitor tellus, id bibendum magna tortor ut felis. In fringilla vel est ac hendrerit. Sed eget congue nisl. Nullam nec tellus id enim lacinia ultricies fermentum tincidunt metus. Vestibulum et nibh volutpat dui auctor rutrum at pretium turpis. Nulla a lacinia enim, sit amet sagittis massa. Quisque congue turpis vel ipsum elementum, eu semper diam vestibulum. Etiam rhoncus mauris ut fermentum vestibulum. Proin bibendum lectus sem. Suspendisse sed turpis et orci gravida commodo sed eget ante. Integer ut egestas purus. Nunc odio erat, maximus quis tristique non, faucibus sit amet tellus. Nullam nec auctor magna, quis facilisis magna. Sed a felis nec augue pharetra tempus quis in neque. Vestibulum magna ligula, luctus a tortor ac, scelerisque semper ex. Aliquam tortor augue, consequat ac egestas vel, molestie et turpis. Aliquam id eros consectetur, venenatis ipsum sit amet, aliquet sapien. Morbi eleifend justo a est elementum, at scelerisque sem interdum. Sed varius mauris sed lorem rutrum, in rhoncus sapien tempus. Donec iaculis gravida orci, ac elementum enim lacinia efficitur. Ut nec neque a nisi luctus bibendum ut vitae turpis. Proin non neque tincidunt, laoreet odio at, condimentum leo. Curabitur finibus risus ac turpis rhoncus, quis elementum arcu condimentum. Aliquam tortor augue, feugiat sed elementum ac, consectetur ut orci. Cras ornare lacus mauris. Suspendisse sed condimentum magna. Donec ultrices ante massa, eu bibendum sem placerat eget. Donec imperdiet elit quis leo lacinia, at accumsan ante tincidunt. Donec volutpat ac quam eu vulputate. Vivamus porta justo sit amet purus consequat lobortis et posuere velit. In hac habitasse platea dictumst. Suspendisse venenatis luctus quam, vitae lobortis leo convallis tristique. Sed in velit semper, imperdiet erat vel, malesuada sapien. Quisque in nisl libero. Sed vestibulum elit ac tortor tincidunt commodo. Nam nec lorem ullamcorper, congue odio ut, pulvinar metus. Morbi fringilla congue nibh a pretium. Proin sodales mi non sem rhoncus condimentum. Morbi faucibus auctor neque sed facilisis. Curabitur gravida elementum augue a tristique. Vivamus sit amet nulla commodo, sodales mauris a, blandit nisl. Donec eget mauris mollis mi laoreet tristique. Quisque condimentum diam quis consectetur convallis. Maecenas mi urna, fringilla a velit in, tempor tempus libero. Phasellus gravida, nunc a luctus auctor, justo velit interdum urna, eu porttitor urna quam eget metus. Pellentesque non ante eget nisi aliquet ullamcorper. Fusce mollis eget orci ut iaculis. Nunc vitae tristique urna. Cras mauris quam, volutpat non ipsum et, ultricies scelerisque erat. Aliquam erat volutpat. Nulla libero lacus, pulvinar et iaculis nec, varius et urna. Proin lorem ante, posuere vel magna sed, placerat pellentesque odio.",
	0
};

const static char	*test_srcs[] = {
	"Lorem ipsum dolor sit amet, consectetur.",
	"non, placerat porttitor velit. ",
	"consequat ac egestas vel, molestie et turpis. Aliquam",
	"\n",
	" ",
	"",
	0
};

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

static int
	test_single_b(const char *tdst, const char *tsrc, size_t tsize, size_t buffer_size)
{
	char	test_dst[buffer_size];
	char	corr_dst[buffer_size];
	size_t	tret;
	size_t	cret;
	size_t	tdst_size;

	tdst_size = strlen(tdst);
	memset(test_dst, 0, tsize);
	memset(corr_dst, 0, tsize);
	memcpy(test_dst, tdst, tdst_size);
	memcpy(corr_dst, tdst, tdst_size);

	cret = strlcat(corr_dst, tsrc, tsize);
	tret = ft_strlcat(test_dst, tsrc, tsize);
	if (tret != cret)
	{
		printf("Failed test_single for ft_strlcat! Expected return:%zu got:%zu\n", cret, tret);
		return (0);
	}
	if (memcmp(test_dst, corr_dst, tsize))
	{
		printf("Failed test_single for ft_strlcat! Expected:\n%s\ngot:\n%s\n", corr_dst, test_dst);
		return (0);
	}
	return (1);
}

static int
	test_single(const char *tdst, const char *tsrc, size_t tsize)
{
	return (test_single_b(tdst, tsrc, tsize, 4048));
}

static int
	test_insufficient()
{
	size_t	dst_index;
	size_t	src_index;
	size_t	dstlen;
	size_t	index;

	dst_index = 0;
	while (test_dsts[dst_index])
	{
		dstlen = strlen(test_dsts[dst_index]);
		src_index = 0;
		while (test_srcs[src_index])
		{
			index = 0;
			while (index <= dstlen)
			{
				if (!test_single(test_dsts[dst_index], test_srcs[src_index], index))
				{
					printf("At test_insufficient for ft_strlcat, dst_index:%zu src_index:%zu index:%zu\n", dst_index, src_index, index);
					return (0);
				}
				index++;
			}
			src_index++;
		}
		dst_index++;
	}
	return (1);
}

static int
	test_strings_fit()
{
	size_t	dst_index;
	size_t	src_index;
	size_t	dstlen;
	size_t	srclen;

	dst_index = 0;
	while (test_dsts[dst_index])
	{
		dstlen = strlen(test_dsts[dst_index]);
		src_index = 0;
		while (test_srcs[src_index])
		{
			srclen = strlen(test_srcs[src_index]);
			if (!test_single(test_dsts[dst_index], test_srcs[src_index], dstlen + srclen + 1))
			{
				printf("At test_strings_fit for ft_strlcat, dst_index:%zu src_index:%zu\n", dst_index, src_index);
				return (0);
			}
			src_index++;
		}
		dst_index++;
	}
	return (1);
}

static int
	test_strings_no_fit()
{
	size_t	dst_index;
	size_t	src_index;
	size_t	dstlen;
	size_t	srclen;
	size_t	index;

	dst_index = 0;
	while (test_dsts[dst_index])
	{
		dstlen = strlen(test_dsts[dst_index]);
		src_index = 0;
		while (test_srcs[src_index])
		{
			srclen = strlen(test_srcs[src_index]);
			index = 0;
			while (index <= (srclen + 1))
			{
				if (!test_single(test_dsts[dst_index], test_srcs[src_index], dstlen + index))
				{
					printf("At test_strings_no_fit for ft_strlcat, dst_index:%zu src_index:%zu index:%zu\n", dst_index, src_index, index);
					return (0);
				}
				index++;
			}
			src_index++;
		}
		dst_index++;
	}
	return (1);
}

static int
	test_segfaults()
{
	char	temp[1024 * 1000];
	char	*str = "Hallo";
	
	memset(temp, 0xFF, 1024 * 1000);
	//memset(temp, 0xFF, (1024 * 1000) - 10);
	return (test_single_b(temp, str, 1024 * 1000, 1024 * 1001));
}

int
	test_strlcat()
{
	int	ret;

	ret = 1;
	if (!test_insufficient())
		ret = 0;
	if (!test_strings_fit())
		ret = 0;
	if (!test_strings_no_fit())
		ret = 0;
	if (!test_segfaults())
		ret = 0;
	return (ret);
}