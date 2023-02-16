/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:56:46 by lulaens           #+#    #+#             */
/*   Updated: 2023/02/14 09:41:08 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <readline/readline.h>
#include <signal.h>

void	ft_ctrl_c(int signum)
{
	(void)signum;
	ft_putstr_fd("\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}
/*
void	ft_ctrl_d(int signum)
{
	(void)signum;
	exit(0);
}*/

void	ft_signal(void)
{
	signal(SIGINT, &ft_ctrl_c);
//	signal(SIGTSTP, &ft_ctrl_d);
	signal(SIGQUIT, SIG_IGN);
}

void	ft_check_line(char *line)
{
	if (!line)
	{
		printf("\n");
		exit(1);
	}
}
