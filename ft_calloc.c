/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaarous <slaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 21:40:41 by slaarous          #+#    #+#             */
/*   Updated: 2026/10/16 21:40:01 by slaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	void	*s;

	if (size == 0 || nmemb == 0)
	{
		size = 1;
		nmemb = 1;
	}
	if (nmemb > SIZE_MAX / size) // remove sizemax
		return (NULL);
	total = nmemb * size;
	s = malloc(total);
	if (!s)
		return (NULL);
	ft_bzero(s, total);
	return (s);
}
