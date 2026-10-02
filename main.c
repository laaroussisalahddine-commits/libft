#include "libft.h"

static void	test_strlcat(char *dst, const char *src, size_t size)
{
	char		dst1[100];
	char		dst2[100];
	size_t		ft_ret;
	size_t		original_ret;

	strcpy(dst1, dst);
	strcpy(dst2, dst);

	ft_ret = ft_strlcat(dst1, src, size);
	original_ret = strlcat(dst2, src, size);

	printf("dst   : \"%s\"\n", dst);
	printf("src   : \"%s\"\n", src);
	printf("size  : %zu\n", size);
	printf("ft_strlcat  -> return: %zu, result: \"%s\"\n",
		ft_ret, dst1);
	printf("strlcat     -> return: %zu, result: \"%s\"\n",
		original_ret, dst2);

	if (ft_ret == original_ret && strcmp(dst1, dst2) == 0)
		printf("RESULT: OK\n\n");
	else
		printf("RESULT: KO\n\n");
}

int	main(void)
{
	test_strlcat("Hello", " World", 20);
	test_strlcat("Hello", " World", 8);
	test_strlcat("Hello", " World", 6);
	test_strlcat("", "Hello", 10);
	test_strlcat("Hello", "", 10);
	test_strlcat("Hello", " World", 0);
	test_strlcat("Hello", " World", 3);
	test_strlcat("12345", "ABC", 6);
	test_strlcat("12345", "ABC", 10);
	return (0);
}
