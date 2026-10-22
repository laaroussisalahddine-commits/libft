/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaarous <slaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 21:44:25 by slaarous          #+#    #+#             */
/*   Updated: 2026/10/22 17:49:12 by slaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_long(const char *str, int sign, int pos)
{
	unsigned long	final_number;
	unsigned long	check;
	int				i;

	i = pos;
	final_number = 0;
	while (ft_isdigit(str[i]))
	{
		check = str[i] - '0';
		if (sign == 1 && final_number > (9223372036854775807 - check) / 10)
			return (-1);
		else if (sign == -1
			&& final_number > (9223372036854775807 - check + 1) / 10)
			return (0);
		final_number = final_number * 10 + check;
		i++;
	}
	return (final_number * sign);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	return (ft_check_long(str, sign, i));
}
