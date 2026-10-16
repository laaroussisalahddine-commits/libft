/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaarous <slaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 21:29:24 by slaarous          #+#    #+#             */
/*   Updated: 2026/10/16 14:19:20 by slaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void	*))
{
	t_list	*perv;

	if (!*lst || !del)
		return ;
	while (*lst != NULL)
	{
		perv = (*lst)-> next;
		del((*lst)-> content);
		free(*lst);
		*lst = perv;
	}
}
