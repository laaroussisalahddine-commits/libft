/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaarous <slaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 20:57:00 by slaarous          #+#    #+#             */
/*   Updated: 2026/10/14 11:34:29 by slaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	end_of_string(const char *str, const char *set)
{
	int	i;

	i = ft_strlen(str);
	while (i > 0 && ft_strchr(set, str[i - 1]))
		i--;
	return (i);
}

int	start_of_string(const char *str, const char *set)
{
	int	i;

	i = 0;
	while (str[i] && ft_strchr(set, str[i]))
		i++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
    int	total;
    int	start;
    int	end;
    int	i;
    char	*new;
    
	start = start_of_string(s1,set);
	end = end_of_string(s1,set);
	if (!s1)
	{
		new = malloc(1);
		if (!new)
			return(NULL);
		new[0] = 0;
	}
	if (end <= start)
        total = 0;
	else
		total = end - start;
	new = (char *)malloc(total + 1);
	if (!new)
		return(NULL);
	i = 0;
	while (start <= end)
	{
		new[i] = s1[start];
		i++;
		start++;	
	}
	new[i] = 0;
	return (new);
}
