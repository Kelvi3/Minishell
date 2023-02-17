/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:43:07 by lulaens           #+#    #+#             */
/*   Updated: 2023/02/17 11:25:41 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	ft_check_digit(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[0] != '-' && ft_isdigit(cmd[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	free_exit(t_list **envcp, t_list **export)
{
	free_lst(envcp);
	free_lst(export);
}

static void	ft_error_exit(int flag, t_list **envcp, t_list **envv)
{
	if (flag == 0)
	{
		printf("exit\n");
		ft_putstr_fd("bash : exit : numeric argument required\n", 2);
		free_exit(envcp, envv);
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

int	test(char *cmd, long digit, t_list **envcp, t_list **export)
{
	printf("exit\n");
	if (cmd)
		digit = atol(cmd);
	free_exit(envcp, export);
	return (digit);
}
int	ft_last_char(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i + 1] == '\0')
		{
			printf("%c\n", cmd[i]);
		//	if (cmd[i] == '8')
		//		return (2);
			if (cmd[i] >= '8')
				return (1);
		}
		i++;
	}
	return (0);
}
/* exit code = digit*/
int	ft_exit(char **cmd, t_list **envcp, t_list **export)
{
	int			j;
	long long	digit;

	j = 0;
	digit = 0;
	if ((ft_len(cmd) > 2 && ft_check_digit(cmd[1]) == 0
			&& ft_check_digit(cmd[2]) == 0) || (ft_len(cmd) > 2
			&& ft_check_digit(cmd[1]) == 0
			&& ft_check_digit(cmd[2]) == 1))
	{
		ft_error_exit(2, envcp, export);
		return (0);
	}
	else if (ft_len(cmd) > 2 && ft_check_digit(cmd[1]) == 1)
	{
		if (ft_check_digit(cmd[2]) == 0)
			ft_error_exit(0, envcp, export);
		ft_error_exit(1, envcp, export);
	}
	else if ((ft_len(cmd) == 2 && ft_check_digit(cmd[1]) == 1))
		ft_error_exit(0, envcp, export);
	digit = test(cmd[1], digit, envcp, export);
	if ((ft_strlen(cmd[1]) >= 20 && ft_last_char(cmd[1]) == 1)
		|| (ft_strlen(cmd[1]) >= 19 && ft_last_char(cmd[1]) == 1))
		ft_error_exit(0, envcp, export);
	exit(digit % 256);
}
