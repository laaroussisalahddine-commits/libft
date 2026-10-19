/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaarous <slaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 13:09:32 by slaarous          #+#    #+#             */
/*   Updated: 2026/10/19 14:35:53 by slaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*s1;
	unsigned const char	*s2;

	s1 = (unsigned char *)dst;
	s2 = (const unsigned char *)src;
	if (len == 0 || dst == src)
		return (dst);
	if (s2 > s1)
		dst = ft_memcpy(s1, s2, len);
	else
	{
		while (len > 0)
		{
			s1[len - 1] = s2[len - 1];
			len--;
		}
	}
	return (dst);
}
