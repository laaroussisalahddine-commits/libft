/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaarous <slaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:15:08 by slaarous          #+#    #+#             */
/*   Updated: 2026/10/19 17:33:25 by slaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	lsrc;
	size_t	ldst;

	ldst = 0;
	while (ldst < size && dst[ldst])
		ldst++;
	lsrc = ft_strlen(src);
	if (size <= ldst)
		return (size + lsrc);
	i = ldst;
	j = 0;
	while (i < size - 1 && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = 0;
	return (ldst + lsrc);
}
