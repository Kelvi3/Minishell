/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envcp_for_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:53:24 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/01 16:00:34 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*void	ft_copy_envcp_in_struct(t_list **envcp)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *envcp;
	(*envcp)->pipe = malloc(sizeof(t_list *));
	(*envcp)->pipe->envcp = malloc(sizeof(char) * (ft_lstsize(tmp) + 1));
	if (!tmp->pipe->envcp)
		return ;
	(*envcp)->pipe->envcp[i] = ft_strjoin((*envcp)->pipe->envcp[i], tmp->name);
	(*envcp)->pipe->envcp[i] = ft_strdup((*envcp)->name);	
	//tmp->pipe->envcp[i] = ft_strjoin(tmp->pipe->envcp[i], "=");
	while (tmp)
	{
		if (tmp->name && tmp->value)
		{	
			tmp->pipe->envcp[i] = ft_strjoin(tmp->pipe->envcp[i], tmp->name);
			tmp->pipe->envcp[i] = ft_strjoin(tmp->pipe->envcp[i], "=");
			tmp->pipe->envcp[i] = ft_strjoin(tmp->pipe->envcp[i], tmp->value);
		}
		tmp = tmp->next;
		i++;
	}
}*/
