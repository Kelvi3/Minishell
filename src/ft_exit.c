/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:43:07 by lulaens           #+#    #+#             */
/*   Updated: 2023/02/03 16:51:07 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_exit(char **cmd)
{
	int	j;
	int	digit;

	j = 0;
	digit = 0;
	if (ft_len(cmd) > 2)
	{
		printf("exit\n");
		ft_putstr_fd("exit : too many arguments\n", 2);
		return (0);
	}
	while (cmd[1][j])
	{
		if (ft_isdigit(cmd[1][j]) == 0)
		{
			printf("exit\n");
			ft_putstr_fd("exit : numeric argument required\n", 2);
			exit(2);
		}
		j++;
	}
	if (cmd[1])
		digit = ft_atoi(cmd[1]);
	printf("exit\n");
	exit (digit % 256);
}
