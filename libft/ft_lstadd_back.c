/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:48:52 by lulaens           #+#    #+#             */
/*   Updated: 2022/10/18 12:49:28 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new)
		return ;
	if (lst[0] == NULL)
	{
		lst[0] = new;
		return ;
	}
	if (new != NULL && lst != NULL)
	{	
		last = ft_lstlast(*lst);
		last->next = new;
	}
}
