/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 08:56:40 by lulaens           #+#    #+#             */
/*   Updated: 2023/02/01 12:17:56 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// if return 1, print cmd->cmd[1]

int	ft_check_param(char **cmd)
{
	int	j;

	j = 1;
	if (cmd[1][0] && cmd[1][0] == '-')
	{
		while (cmd[1][j] && cmd[1][j] != ' ')
		{
			if (cmd[1][j] != 'n')
				return (1);
			j++;
		}
	}
	return (0);
}

// cmd->cmd[2] == toute la chaine apres le -n

void	ft_echo(char **cmd)
{
	int	i;

	i = 0;
	if (ft_check_param(cmd) == 1) // si pas de -n
		printf("%s\n", cmd[1]);
	else
		printf("%s", cmd[2]);
}
