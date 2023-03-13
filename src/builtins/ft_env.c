/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:08:10 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/10 11:18:54 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	check_after_cmd(char **cmd, int i)
{
	if (cmd[i + 1])
		if (ft_strcmp(cmd[i + 1], "|") == 0)
			return (1);
	return (0);
}

void	ft_env(t_list **envcp, int i)
{
	t_list	*tmp;

	tmp = *envcp;
	if (ft_len(tmp->cmd) > 1 && check_after_cmd(tmp->cmd, i) == 0)
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
