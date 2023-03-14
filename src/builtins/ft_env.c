/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:08:10 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/10 14:59:43 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_env(t_data **envcp)
{
	t_data	*tmp;

	tmp = *envcp;
	if (ft_len(tmp->cmd) > 1)
	{
		g_exit_code = 127;
		ft_putstr_fd("env : error too many arguments\n", 2);
		return ;
	}
	while (tmp->envcp)
	{
		if (tmp->envcp->name && tmp->envcp->value)
			printf("%s=%s\n", tmp->envcp->name, tmp->envcp->value);
		tmp->envcp = tmp->envcp->next;
	}
}
