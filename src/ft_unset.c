/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:28:11 by lulaens           #+#    #+#             */
/*   Updated: 2023/02/02 16:37:57 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"


// key = variable a supprimer

void	ft_unset(char **env, t_list **lst, char *key)
{
	t_list	*head;
	t_list	*cpy;

	cpy = NULL;
	head = *lst;
	while (head)
	{
		if (ft_strncmp(head->value, key, ft_strlen(key)) != 0)
			head = head->next;
		cpy->content = head->content;
		cpy = cpy->next;
		head = head->next;
	}
}
