/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:08:10 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/01 16:59:32 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_env(t_list **envcp)
{
	t_list	*tmp;

	tmp = *envcp;
	if (ft_len(tmp->cmd) > 1)
	{
		g_exit_code = 127;
		ft_putstr_fd("env : error too many arguments\n", 2);
		return ;
	}
	while (tmp)
	{
		if (tmp->name && tmp->value)
			printf("%s=%s\n", tmp->name, tmp->value);
		tmp = tmp->next;
	}
}
