/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:00:47 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/10 14:37:59 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_struct **lst, void (*del)(void *))
{
	t_struct	*tmp;

	if (!lst || !del)
		return ;
	tmp = *lst;
	while (*lst)
	{
		*lst = (*lst)->next;
		del(tmp->content);
		free(tmp);
		tmp = *lst;
	}
	*lst = NULL;
}
