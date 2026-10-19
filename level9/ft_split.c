/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaarous <slaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 13:42:20 by slaarous          #+#    #+#             */
/*   Updated: 2026/10/19 11:32:52 by slaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_word(char const *s, char c, int start);
static int	count_word(char const *s, char c);
static void	free_split(char **arr, int j);

char	**ft_split(char const *s, char c)
{
	char		**arr;
	int			count;
	int			i;
	int			pos;
	int			len;

	count = count_word (s, c);
	arr = (char **)malloc((count + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	pos = 0;
	while (i < count)
	{
		while (s[pos] && s[pos] == c)
			pos++;
		len = len_word(s, c, pos);
		arr[i] = ft_substr(s, pos, len);
		if (!arr[i])
		{
			free_split(arr, i);
			return (NULL);
		}
		pos += len;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

static int	count_word(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
			if (s[i] == '\0')
				return (count);
		}
		i++;
	}
	return (count);
}

static int	len_word(char const *s, char c, int start)
{
	int	len;

	len = 0;
	while (s[start] && s[start] != c)
	{
		len++;
		start++;
	}
	return (len);
}

static void	free_split(char **arr, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		free(arr[i]);
		i++; 
	}
	free(arr);
}
