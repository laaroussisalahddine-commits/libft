#include"libft.h" 

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t 	i;
	size_t 	j;
	size_t 	ldest;
	size_t 	lsrc;

	ldest = ft_strlen(dst);
	lsrc = ft_strlen(src);
	if (size <= ldest)
		return (size + lsrc);
	i = ldest; 
	j = 0;
	while (i < size - 1 && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (ldest + lsrc);
}