/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:56:46 by lulaens           #+#    #+#             */
/*   Updated: 2023/02/20 17:52:40 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <readline/readline.h>
#include <signal.h>

void	ft_ctrl_c(int signum)
{
	(void)signum;
	g_exit_code = 130;
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

void	ft_check_line(char *line, t_list *envcp, t_list *export)
{
	if (!line)
	{
		while (envcp)
		{
			free(envcp->name);
			free(envcp->value);
			envcp = envcp->next;
		}
		free(envcp);
		while (export)
		{
			free(export->name);
			free(export->value);
			export = export->next;
		}
		free(export);
	//	printf("%s\n", export->name);
	/*	(void) export;
		(void) envcp;*/
		printf("\n");
		exit(1);
	}
}
