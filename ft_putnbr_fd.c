/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaarous <slaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 11:04:46 by slaarous          #+#    #+#             */
/*   Updated: 2026/10/14 11:44:39 by slaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlong(long n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	ft_putlong(nb, fd);
}

void	ft_putlong(long n, int fd)
{
	if (n >= 10)
		ft_putlong(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}
