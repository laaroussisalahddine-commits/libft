/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaarous <slaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 20:57:00 by slaarous          #+#    #+#             */
/*   Updated: 2026/10/13 22:44:08 by slaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int end_of_string(char *str, char *set)
{
    int i;
    int j;

    i = ft_strlen(str) - 1;
	j = ft_strlen(set) - 1;
    while (i > 0)
    {
		j = 0;
        while (j > 0)
			j--;
        i--;
    }
    return(i);
}

int start_of_string(char *str, char *set)
{
    int i;
    int j;

    i = 0;
    while (str[i] && str[i] == set[i])
    {
        j = 0;
        while (set[j] && str[i] == set[j])
			j++;
        i++;
    }
    return(i);
}

int total_set(char *str , char *set)
{
    int		i;
    int		j;
    int	count;

	count = 0;
	i = 0; 
    while (str[i])
    {
        j = 0;
        while (set[j])
        {
            if (str[i] == set[j])
            {
                count++;
                break;
            }    
            j++;
        }    
        i++;
    }
    return(count);
}    


char *ft_strtrim(char const *s1, char const *set)
{
    int total;
    int start;
    int end;
    int i;
    char *new;
    
    if (!s1 || !set)
        return (NULL);
    start = start_of_string((char *)s1, (char *)set);
	end = end_of_string((char *)s1, (char *)set);
    total = ft_strlen(s1) - total_set((char *)s1, (char *)set) ;
    new = (char *)malloc(total + 1);
    if (!new)
        return(NULL);
    i = 0;
    while (start < end)
    {
        new[i] = s1[start];
        i++;
        start++;
    }    
    new[i] = 0;
    return (new);
}
