/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaarous <slaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 13:42:20 by slaarous          #+#    #+#             */
/*   Updated: 2026/10/15 15:10:38 by slaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			while (str[i] && str[i] != c)
			{
				len++;
				i++;
			}
			break;
		}
		i++;
	}
	return (i);
}

static int	count_string(char *str, char c)
{
	int	i;
	int	count;
	
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

static	char ft_skip(char const *s, char c)
{
	int		i;
	char	*str;

	str = (char const *)s;
	i = 0;

	while (str[i] && str[i] != c )
		i++;
	return (str + i);
}

static int append (char *str, char *current

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		count;
	char	*current;

	arr = (char **)malloc((count + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (s[i])
	{
		j = 0;
		while (j < 

}


int main ()
{
	
}

