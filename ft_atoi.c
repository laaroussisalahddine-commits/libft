/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaarous <slaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 21:44:25 by slaarous          #+#    #+#             */
/*   Updated: 2026/10/19 15:29:03 by slaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_long(const char *str, int sign, int pos)
{
	long	final_number;
	long	check;
	int		i;

	i = pos;
	final_number = 0;
	while (ft_isdigit(str[i]))
	{
		check =  final_number * 10 + (str[i] - '0');
		if (check > (9223372036854775807 - (str[i] - '0')) / 10)
		{	if (sign == 1)
				return (-1);
			else if (sign == -1)
				return (0);
		} 
		final_number = check;
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
