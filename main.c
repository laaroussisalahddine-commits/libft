#include "level0/libft.h"
#include <stdio.h>
#include <stdlib.h>

static void	test_split(char const *s, char c)
{
	char	**result;
	int		i;

	printf("Input: [%s] | delimiter: [%c]\n", s, c);
	result = ft_split(s, c);
	if (!result)
	{ 
		printf("Allocation failed or NULL returned\n\n");
		return ;
	}
	i = 0;
	while (result[i])
	{
		printf("result[%d] = [%s]\n", i, result[i]);
		free(result[i]);
		i++;
	}
	free(result);
	printf("End of array: NULL\n\n");
}

int	main(void)
{
	test_split("hello world", ' ');
	test_split("  hello   world  ", ' ');
	test_split("hello", ' ');
	test_split("", ' ');
	test_split("     ", ' ');
	test_split("a,,b,c,", ',');
	test_split("42", '2');
	test_split("abc", 'x');
	return (0);
}