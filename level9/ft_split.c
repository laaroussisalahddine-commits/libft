/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaarous <slaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 13:42:20 by slaarous          #+#    #+#             */
/*   Updated: 2026/10/17 00:44:18 by slaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*copy_word(char	const *s, int start, int len);
static int len_word(char const *s, char c, int start);
static int	count_word(char const *s, char c);
static void	free_split(char **arr, int j);

char	**ft_split(char const *s, char c)
{
	char		**arr;
	int			count;
	int			i;
	int 		pos;
	int			len;
	int			start;

	count = count_word (s, c);
	arr = (char	**)malloc((count + 1) * sizeof(char	*));
	if (!arr)
		return (NULL);
	i = 0;
	pos = 0;
	len = 0;
	while (i < count)
	{
		while (s[pos] && s[pos] == c)
			pos++;
		start = pos;
		len = len_word(s, c, start);
		arr[i] = copy_word(s, c, len);
		if (!arr)
		{
			free_split(arr, i);
			return (NULL);
		}
		pos = ft_strlen(arr[i]);
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
			while(s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int len_word(char const *s, char c, int start)
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

static char	*copy_word(char	const *s, int start, int len)
{
	char	*new;
	int		i;

	if (!s)
		return (NULL);
	new = (char	*)malloc(len + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = s[start];
		i++;
		start++;
	}
	new[i] = '\0';
	return (new);
}

static void	free_split(char **arr, int j)
{
	int	i;
	
	i = 0;
	while (i < j)
	{
		free(arr[i]);
		i++; 
	}
	free(arr);
}

