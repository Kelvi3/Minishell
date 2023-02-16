/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 08:56:40 by lulaens           #+#    #+#             */
/*   Updated: 2023/02/16 09:57:06 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// if return 1, print cmd->cmd[1]

int	ft_check_param(char **cmd)
{
	int	i;
	int	j;

	i = 1;
	while (cmd[i])
	{	
		j = 0;
		while (cmd[i][j])
		{

		}
		i++;
	}
	return (0);
}

// cmd->cmd[2] == toute la chaine apres le -n

void	ft_echo(char **cmd)
{
	int	i;

	(void) cmd;
	i = 0;
//	if (ft_check_param(cmd) == 1) /* PAS DE -N */
		printf("%s\n", cmd[1]);
	return ;
}
