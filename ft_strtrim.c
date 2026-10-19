/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaarous <slaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 20:57:00 by slaarous          #+#    #+#             */
/*   Updated: 2026/10/19 17:03:05 by slaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	end_of_string(const char *str, const char *set)
{
	int	i;

	i = ft_strlen(str);
	while (i > 0 && ft_strchr(set, str[i - 1]))
		i--;
	return (i);
}

static int	start_of_string(const char *str, const char *set)
{
	int	i;

	i = 0;
	while (str[i] && ft_strchr(set, str[i]))
		i++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		total;
	int		start;
	int		end;
	char	*new;

	if (!s1)
		return (NULL);
	start = start_of_string(s1, set);
	end = end_of_string(s1, set);
	if (end <= start)
		total = 0;
	else
		total = end - start;
	new = ft_substr(s1, start, total);
	return (new);
}
