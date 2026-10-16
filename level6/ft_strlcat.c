#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	lsrc;
	size_t	ldst;

	ldst = ft_strlen(dst);
	lsrc = ft_strlen(src);
	if (size <= ldst)
		return (size + lsrc);
	i = ldst;
	j = 0;	
	while (i < size - 1 && src[j])
	{
		dst[i] =  src[j];
		i++;
		j++;
	}
	dst[i] = 0;
	return (ldst + lsrc);
}