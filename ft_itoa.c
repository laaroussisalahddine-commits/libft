/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaarous <slaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 12:58:15 by slaarous          #+#    #+#             */
/*   Updated: 2026/10/18 15:40:37 by slaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_number(long n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n >= 10)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

static int	count_negative(long n)
{
	long	count;

	count = 0;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*new;
	long	temp;
	int		len;
	int		count_sign;
	int		i;

	temp = n;
	len = count_number(temp);
	count_sign = count_negative(temp);
	new = (char *)malloc(len + 1);
	if (!new)
		return (NULL);
	if (temp < 0)
		temp = -temp;
	i = len;
	while (i > 0)
	{
		new[i - 1] = ((temp % 10) + '0');
		temp = temp / 10;
		i--;
	}
	if (count_sign == 1)
		new[0] = '-';
	new[len] = '\0';
	return (new);
}
