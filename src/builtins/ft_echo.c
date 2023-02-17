/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 08:56:40 by lulaens           #+#    #+#             */
/*   Updated: 2023/02/17 11:31:32 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// if return 1, print cmd->cmd[1]

int	ft_check_param(char **cmd)
{
	int	i;

	i = 1;
	if (cmd[1][0] == '-')
	{
		while (cmd[1][i])
		{
			if (cmd[1][i] != 'n')
				return (1);
			i++;
		}
		if (cmd[1][i] == '\0')
			return (2);
	}
	return (0);
}

// cmd->cmd[2] == toute la chaine apres le -n

void	ft_echo(char **cmd)
{
	int	i;

	(void) cmd;
	i = 1;
	g_exit_code = 0;
	/* echo -nnnn bonjour */
	if (ft_len(cmd) >= 2 && ft_check_param(cmd) == 2)
	{
		i = 2;
		while (cmd[i])
		{
			printf("%s", cmd[i]);
			i++;
		}
	}
	/* echo bonjour */
	else if (ft_len(cmd) >= 2 && (ft_check_param(cmd) == 0 || ft_check_param(cmd) == 1))
	{
		i = 1;
		while (cmd[i])
		{
			printf("%s ", cmd[i]);
			i++;
			if (i == ft_len(cmd))
				printf("\n");
		}
	}
	return ;
}
