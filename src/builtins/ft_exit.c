/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:43:07 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/14 11:11:48 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	ft_error_exit(int flag, t_list **envcp, t_list **envv)
{
	if (flag == 0)
	{
		ft_putstr_fd("bash : exit : numeric argument required\n", 2);
		exit(2);
	}
	if (flag == 1)
	{
		ft_putstr_fd("bash : exit : too many arguments\n", 2);
		free_exit(envcp, envv);
		exit(2);
	}
	if (flag == 2)
	{
		printf("exit\n");
		ft_putstr_fd("bash : exit : too many arguments\n", 2);
	}
}

int	ft_last_char(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i + 1] == '\0')
		{
			if (cmd[i] == '9')
				return (2);
			if (cmd[i] >= '8')
				return (1);
		}
		i++;
	}
	return (0);
}

static int	ft_exit_condition(char **cmd, t_list **envcp, t_list **export)
{
	if ((ft_len(cmd) > 2 && ft_check_digit(cmd[1]) == 0
			&& ft_check_digit(cmd[2]) == 0) || (ft_len(cmd) > 2
			&& ft_check_digit(cmd[1]) == 0
			&& ft_check_digit(cmd[2]) == 1))
	{
		ft_error_exit(2, envcp, export);
		g_exit_code = 1;
		return (0);
	}
	return (1);
}

int	check_after_cmd(char **cmd)
{
	int	i;

	i = 1;
	if (ft_strcmp(cmd[i], "|") == 0)
		return (1);
	return (0);
}

int	ft_exit(char **cmd, t_list **envcp, t_list **export)
{
	int			j;
	long long	digit;

	j = 0;
	digit = 0;
//	if ((*envcp)->cmd[1])
//		if (ft_strcmp((*envcp)->cmd[1], "|") == 0)
//			return (0);
	if (ft_exit_condition(cmd, envcp, export) == 0)
		return (0);
	else if (ft_len(cmd) > 2 && ft_check_digit(cmd[1]) == 1)
	{
		if (ft_check_digit(cmd[2]) == 0)
			ft_error_exit(0, envcp, export);
		ft_error_exit(1, envcp, export);
	}
	else if ((ft_len(cmd) == 2 && ft_check_digit(cmd[1]) == 1))
		ft_error_exit(0, envcp, export);
	digit = exit_atol(cmd[1], digit, envcp, export);
	if (cmd[1])
	{
		if ((ft_strlen(cmd[1]) >= 20 && ft_last_char(cmd[1]) == 2)
			|| (ft_strlen(cmd[1]) == 19 && ft_last_char(cmd[1]) == 1))
			ft_error_exit(0, envcp, export);
	}
	exit(digit % 256);
}
