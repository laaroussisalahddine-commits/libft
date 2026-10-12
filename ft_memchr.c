/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaarous <slaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 20:44:56 by slaarous          #+#    #+#             */
/*   Updated: 2026/10/12 21:28:19 by slaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	caractere;
	size_t			i;

	str = (unsigned char *)s;
	caractere = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == caractere)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
