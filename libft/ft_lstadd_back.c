/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:48:52 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/10 14:36:34 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_struct **lst, t_struct *new)
{
	t_struct	*last;

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
