/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddfront.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:26:17 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/10 15:44:20 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_lstaddfront(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (lst)
	{
		new->next = *lst;
		*lst = new;
	}
	else
		new->next = NULL;
}
