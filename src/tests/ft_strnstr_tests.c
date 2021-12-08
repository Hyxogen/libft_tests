#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

const static char 	*haystacks[] = {
	"Hallo dit is een string",
	"Hallo",
	" string",
	" ",
	"\n",
	"",
	"Lorem ipsum dolor sit amet, consectetur adipiscing elit.\nDonec non dictum mauris, eu dignissim turpis. Maecenas lorem justo, suscipit nec nisl non, placerat porttitor velit. Aenean cursus nibh nec porttitor rhoncus. Sed malesuada, arcu quis malesuada dictum, arcu metus interdum odio, in condimentum eros erat eget enim. Donec ultricies ante quam, in vulputate orci imperdiet at. Nam pellentesque, ex quis bibendum lacinia, arcu libero porttitor tellus, id bibendum magna tortor ut felis. In fringilla vel est ac hendrerit. Sed eget congue nisl. Nullam nec tellus id enim lacinia ultricies fermentum tincidunt metus. Vestibulum et nibh volutpat dui auctor rutrum at pretium turpis. Nulla a lacinia enim, sit amet sagittis massa. Quisque congue turpis vel ipsum elementum, eu semper diam vestibulum. Etiam rhoncus mauris ut fermentum vestibulum. Proin bibendum lectus sem. Suspendisse sed turpis et orci gravida commodo sed eget ante. Integer ut egestas purus. Nunc odio erat, maximus quis tristique non, faucibus sit amet tellus. Nullam nec auctor magna, quis facilisis magna. Sed a felis nec augue pharetra tempus quis in neque. Vestibulum magna ligula, luctus a tortor ac, scelerisque semper ex. Aliquam tortor augue, consequat ac egestas vel, molestie et turpis. Aliquam id eros consectetur, venenatis ipsum sit amet, aliquet sapien. Morbi eleifend justo a est elementum, at scelerisque sem interdum. Sed varius mauris sed lorem rutrum, in rhoncus sapien tempus. Donec iaculis gravida orci, ac elementum enim lacinia efficitur. Ut nec neque a nisi luctus bibendum ut vitae turpis. Proin non neque tincidunt, laoreet odio at, condimentum leo. Curabitur finibus risus ac turpis rhoncus, quis elementum arcu condimentum. Aliquam tortor augue, feugiat sed elementum ac, consectetur ut orci. Cras ornare lacus mauris. Suspendisse sed condimentum magna. Donec ultrices ante massa, eu bibendum sem placerat eget. Donec imperdiet elit quis leo lacinia, at accumsan ante tincidunt. Donec volutpat ac quam eu vulputate. Vivamus porta justo sit amet purus consequat lobortis et posuere velit. In hac habitasse platea dictumst. Suspendisse venenatis luctus quam, vitae lobortis leo convallis tristique. Sed in velit semper, imperdiet erat vel, malesuada sapien. Quisque in nisl libero. Sed vestibulum elit ac tortor tincidunt commodo. Nam nec lorem ullamcorper, congue odio ut, pulvinar metus. Morbi fringilla congue nibh a pretium. Proin sodales mi non sem rhoncus condimentum. Morbi faucibus auctor neque sed facilisis. Curabitur gravida elementum augue a tristique. Vivamus sit amet nulla commodo, sodales mauris a, blandit nisl. Donec eget mauris mollis mi laoreet tristique. Quisque condimentum diam quis consectetur convallis. Maecenas mi urna, fringilla a velit in, tempor tempus libero. Phasellus gravida, nunc a luctus auctor, justo velit interdum urna, eu porttitor urna quam eget metus. Pellentesque non ante eget nisi aliquet ullamcorper. Fusce mollis eget orci ut iaculis. Nunc vitae tristique urna. Cras mauris quam, volutpat non ipsum et, ultricies scelerisque erat. Aliquam erat volutpat. Nulla libero lacus, pulvinar et iaculis nec, varius et urna. Proin lorem ante, posuere vel magna sed, placerat pellentesque odio.",
	"placerat porttitor velit.",
	0
};

static int
	test_single(const char *haystack, const char *needle, size_t len)
{
	char	*tret;
	char	*cret;

	tret = ft_strnstr(haystack, needle, len);
	cret = strnstr(haystack, needle, len);
	if (tret != cret)
	{
		printf("Needle:\"%s\" haystack:\"%s\" len:%zu\n", needle, haystack, len);
		printf("Failed test_single for ft_strnstr. Expected:%lx got:%lx\n", (unsigned long) cret, (unsigned long) tret);
		return (0);
	}
	return (1);
}

static int
	test_all_words_l(const char* str, size_t len)
{
	char	buf[4048];
	char	*temp;
	char	*word;
	size_t	hlen;

	temp = &buf[0];
	hlen = strlen(str);
	memset(temp, 0, 4048);
	memcpy(temp, str, hlen);
	while (1)
	{
		word = strsep(&temp, " ");
		if (!word)
			break;
		if (!test_single(str, word, len))
		{
			printf("At test_all_words_l. word:\"%s\" len:%zu\n", word, len);
			return (0);
		}
	}
	return (1);
}

//No find version
static int
	test_all_words_l_morphed(const char* str, size_t len)
{
	char	buf[4048];
	char	*temp;
	char	*word;
	size_t	hlen;

	temp = &buf[0];
	hlen = strlen(str);
	memset(temp, 0, 4048);
	memcpy(temp, str, hlen);
	while (1)
	{
		word = strsep(&temp, " ");
		if (!word)
			break;
		if (*word)
			*word = *word + 1;
		if (!test_single(str, word, len))
		{
			printf("At test_all_words_l_morphed. word:\"%s\" len:%zu\n", word, len);
			return (0);
		}
	}
	return (1);
}

static int
	test_all_words(const char* str)
{
	size_t	len;

	len = strlen(str);
	while (len)
	{
		if (!test_all_words_l(str, len))
		{
			printf("At test_all_words. n:%zu\n", len);
			return (0);
		}
		len--;
	}
	return (1);
}

static int
	test_all_haystacks()
{
	int	index;

	index = 0;
	while (haystacks[index])
	{
		if (!test_all_words(haystacks[index]))
		{
			printf("At test_all_haystacks. index:%d\n\n", index);
			return (0);
		}
		index++;
	}
	return (1);
}

static int
	test_all_haystacks_morphed()
{
	int	index;

	index = 0;
	while (haystacks[index])
	{
		if (!test_all_words_l_morphed(haystacks[index], strlen(haystacks[index])))
		{
			printf("At test_all_haystacks_morphed. index:%d\n\n", index);
			return (0);
		}
		index++;
	}
	return (1);
}

static int
	test_needle_reset()
{
	if (!test_single("aaabcabcd", "aabc", -1))
	{
		printf("At test_needle_reset\n\n");
		return (0);
	}
	if (!test_single("", "coucou", -1))
	{
		printf("At test_needle_reset. Empty coucou\n\n");
		return (0);
	}
	return (1);
}

int
	test_strnstr()
{
	int	ret;

	ret = 1;
	ft_strnstr("lorem ipsum dolor sit amet", "sit", 10);
	if (!test_all_haystacks())
		ret = 0;
	if (!test_all_haystacks_morphed())
		ret = 0;
	if (!test_needle_reset())
		ret = 0;
	return (ret);
}
