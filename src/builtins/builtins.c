/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:51:31 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/01 10:51:31 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <readline/history.h>
#include <unistd.h>

/* fonction qui check si y'a un pipe apres + une redirection apres la commande */
/* si ya minimum 1 pipe apres , ne pas executer le premiere commande */
/* sauf si y'a une redirection et que la commande affiche qlq chose */

int	ft_check_pipe(char **cmd)
{
	int	i;

	i = 1;
	while (cmd[i])
	{
		if (ft_strncmp(cmd[i], "|", 1) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_redirection(char **cmd)
{
	int	i;

	i = 1;
	while (cmd[i])
	{
		if (ft_strncmp(cmd[i], ">", 1) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	ft_builtins(char **cmd, char *line, t_list **envcp, t_list **export)
{
//	if (ft_check_pipe(cmd) == 0 || ft_check_redirection(cmd) == 0)
//	{
		/* add l'exec des var env dans tout les builtins */
		if (ft_strcmp(cmd[0], "$") == 0)
		{
			cmd[0] = ft_strdup(ft_check_doll(cmd, envcp, 0));
			printf("%s\n", cmd[0]);
		}	
		if (ft_strcmp(cmd[0], "echo") == 0)
			ft_echo(cmd, envcp, line);
		else if (ft_strcmp(cmd[0], "cd") == 0)
			ft_cd(cmd, envcp);
		else if (ft_strcmp(cmd[0], "pwd") == 0)
			ft_pwd(cmd, envcp);
		else if (ft_strcmp(cmd[0], "export") == 0)
			ft_export(cmd, line, envcp, export);
		else if (ft_strcmp(cmd[0], "unset") == 0)
		{
			ft_unset(cmd, export, 0);
			ft_unset(cmd, envcp, 1);
		}
		else if (ft_strcmp(cmd[0], "env") == 0)
			ft_env(envcp, cmd);
		else if (ft_strcmp(cmd[0], "exit") == 0)
			ft_exit(cmd, envcp, export);
//	}
//	else
//		return ;
	/* else exec les redirection si checkredirection == 1 */
}
