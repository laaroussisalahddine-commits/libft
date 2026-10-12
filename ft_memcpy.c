/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaarous <slaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 19:45:34 by slaarous          #+#    #+#             */
/*   Updated: 2026/10/12 21:03:49 by slaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*str;
	size_t			i;

	dest = (unsigned char *)dst;
	str = (unsigned char *)src;
	if (n == 0)
		return (dst);
	i = 0;
	while (i < n)
	{
		dest[i] = str[i];
		i++;
	}
	return ((unsigned char *)dst);
}
