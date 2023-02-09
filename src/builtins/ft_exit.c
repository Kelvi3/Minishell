/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:43:07 by lulaens           #+#    #+#             */
/*   Updated: 2023/02/09 14:42:55 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	ft_check_digit(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (ft_isdigit(cmd[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

static void	ft_error_exit(int flag)
{
	if (flag == 0)
	{
		printf("exit\n");
		ft_putstr_fd("bash : exit : numeric argument required\n", 2);
		exit(2);
	}
	if (flag == 1)
	{
		ft_putstr_fd("bash : exit : too many arguments\n", 2);
		exit(2);
	}
	if (flag == 2)
	{
		printf("exit\n");
		ft_putstr_fd("bash : exit : too many arguments\n", 2);
	}
}

int	ft_exit(char **cmd)
{
	int	j;
	int	digit;

	j = 0;
	digit = 0;
	if ((ft_len(cmd) > 2 && ft_check_digit(cmd[1]) == 0
			&& ft_check_digit(cmd[2]) == 0) || (ft_len(cmd) > 2
			&& ft_check_digit(cmd[1]) == 0
			&& ft_check_digit(cmd[2]) == 1))
	{
		ft_error_exit(2);
		return (0);
	}
	else if (ft_len(cmd) > 2 && ft_check_digit(cmd[1]) == 1)
	{
		if (ft_check_digit(cmd[2]) == 0)
			ft_error_exit(0);
		ft_error_exit(1);
	}
	else if ((ft_len(cmd) == 2 && ft_check_digit(cmd[1]) == 1))
		ft_error_exit(0);
	printf("exit\n");
	if (cmd[1])
		digit = ft_atoi(cmd[1]);
	exit(digit % 256);
}
