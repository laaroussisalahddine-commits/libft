
#include "libft.h"

static int	check_split(char const *s, char c, char **expected)
{
	char	**result;
	int		i;
	int		ok;

	result = ft_split(s, c);
	if (!result)
		return (0);
	i = 0;
	ok = 1;
	while (expected[i] && result[i])
	{
		if (strcmp(result[i], expected[i]) != 0)
			ok = 0;
		i++;
	}
	if (expected[i] || result[i])
		ok = 0;
	i = 0;
	while (result[i])
		free(result[i++]);
	free(result);
	return (ok);
}

int	main(void)
{
	char	*e1[] = {"hello", NULL};
	char	*e2[] = {"hello", "world", NULL};
	char	*e3[] = {NULL};
	char	*e4[] = {"a", "b", NULL};
	char	*e5[] = {"a", "b", "c", NULL};
	char	*e6[] = {"x", NULL};
	char	*e7[] = {"123", "456", "789", NULL};
	char	*e8[] = {"b", "n", "n", NULL};
	char	*e9[] = {"abcdefghij", "klmnopqrst", NULL};
	char	*e10[] = {"one", "two", "three", NULL};
	char	*e11[] = {"UPPER", "lower", "Mixed", NULL};
	char	*e12[] = {"alpha", "beta", "gamma", NULL};
	char	*e13[] = {"start", "middle", "end", NULL};
	char	*e14[] = {"a", "b", "c", "d", NULL};
	char	*e15[] = {"hello", "42", NULL};
	char	*e16[] = {"a", "b", NULL};
	char	*e17[] = {"cat", "dog", NULL};
	char	*e18[] = {"123", "45", "6", NULL};
	char	*e19[] = {"red", "green", "blue", NULL};
	char	*e20[] = {"libft", NULL};

	printf("Test 01: %s\n",
		check_split("", ' ', e3) ? "PASS" : "FAIL");
	printf("Test 02: %s\n",
		check_split("   ", ' ', e3) ? "PASS" : "FAIL");
	printf("Test 03: %s\n",
		check_split("hello", ' ', e1) ? "PASS" : "FAIL");
	printf("Test 04: %s\n",
		check_split("hello world", ' ', e2) ? "PASS" : "FAIL");
	printf("Test 05: %s\n",
		check_split("  hello   world  ", ' ', e2) ? "PASS" : "FAIL");
	printf("Test 06: %s\n",
		check_split(",a,b,", ',', e4) ? "PASS" : "FAIL");
	printf("Test 07: %s\n",
		check_split("a,,b,,,c", ',', e5) ? "PASS" : "FAIL");
	printf("Test 08: %s\n",
		check_split("x", ' ', e6) ? "PASS" : "FAIL");
	printf("Test 09: %s\n",
		check_split("x", 'x', e3) ? "PASS" : "FAIL");
	printf("Test 10: %s\n",
		check_split("123 456 789", ' ', e7) ? "PASS" : "FAIL");
	printf("Test 11: %s\n",
		check_split("banana", 'a', e8) ? "PASS" : "FAIL");
	printf("Test 12: %s\n",
		check_split("abcdefghij klmnopqrst", ' ', e9) ? "PASS" : "FAIL");
	printf("Test 13: %s\n",
		check_split("one,two,three,", ',', e10) ? "PASS" : "FAIL");
	printf("Test 14: %s\n",
		check_split("UPPER lower Mixed", ' ', e11) ? "PASS" : "FAIL");
	printf("Test 15: %s\n",
		check_split("alpha,beta,gamma", ',', e12) ? "PASS" : "FAIL");
	printf("Test 16: %s\n",
		check_split("start---middle---end", '-', e13)
		? "PASS" : "FAIL");
	printf("Test 17: %s\n",
		check_split("a-b-c-d", '-', e14) ? "PASS" : "FAIL");
	printf("Test 18: %s\n",
		check_split("hello 42", ' ', e15) ? "PASS" : "FAIL");
	printf("Test 19: %s\n",
		check_split("a\tb", '\t', e16) ? "PASS" : "FAIL");
	printf("Test 20: %s\n",
		check_split("cat dog", ' ', e17) ? "PASS" : "FAIL");
	printf("Test 21: %s\n",
		check_split("123045006", '0', e18) ? "PASS" : "FAIL");
	printf("Test 22: %s\n",
		check_split("red,green,blue", ',', e19) ? "PASS" : "FAIL");
	printf("Test 23: %s\n",
		check_split("libft", ',', e20) ? "PASS" : "FAIL");
	printf("Test 24: %s\n",
		check_split(",,,,", ',', e3) ? "PASS" : "FAIL");
	printf("Test 25: %s\n",
		check_split(":::::", ':', e3) ? "PASS" : "FAIL");
	printf("Test 26: %s\n",
		check_split("  a  b  ", ' ', e4) ? "PASS" : "FAIL");
	printf("Test 27: %s\n",
		check_split("a\nb", '\n', e16) ? "PASS" : "FAIL");
	printf("Test 28: %s\n",
		check_split("a/b//c", '/', e5) ? "PASS" : "FAIL");
	printf("Test 29: %s\n",
		check_split("a;b;;c", ';', e5) ? "PASS" : "FAIL");
	printf("Test 30: %s\n",
		check_split("a+b++c", '+', e5) ? "PASS" : "FAIL");

	return (0);
}
