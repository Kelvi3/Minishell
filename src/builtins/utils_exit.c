/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:03:39 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/01 17:08:22 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_check_digit(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[0] != '+' && cmd[0] != '-' && ft_isdigit(cmd[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	exit_atol(char *cmd, long digit, t_list **envcp, t_list **export)
{
	printf("exit\n");
	if (cmd)
		digit = ft_atoi(cmd);
	free_exit(envcp, export);
	return (digit);
}

void	free_exit(t_list **envcp, t_list **export)
{
	free_lst(envcp);
	free_lst(export);
}
