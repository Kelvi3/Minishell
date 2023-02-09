/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:28:11 by lulaens           #+#    #+#             */
/*   Updated: 2023/02/09 14:43:11 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// key = variable a supprimer
// key = lst->name
t_list	*ft_unset(t_list *envcp, char **key)
{
	int		i;
	t_list	*t_tmp;
	t_list	*tmp;

	i = 1;

	tmp = envcp;
	if (ft_len(key) == 1)
		return (NULL);
	while (ft_strncmp(key[i], tmp->next->name, ft_strlen(tmp->name)) != 0)
		tmp = tmp->next;
	t_tmp = tmp->next;
	tmp->next = t_tmp->next;
	return (envcp);
}
