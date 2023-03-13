/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:51:31 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/10 11:19:06 by lulaens          ###   ########.fr       */
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

/* add l'exec des var env dans tout les builtins */

void	ft_builtins(t_list **envcp, t_list **export)
{
	t_list	*lst;

	lst = *envcp;
	if (ft_strcmp(lst->cmd[0], "$") == 0)
	{
		lst->cmd[0] = ft_strdup(ft_check_doll(lst->cmd, envcp, 0));
		/* fonctionne que pour PWD */
		printf("%s\n", lst->cmd[0]);
	}
	if (ft_strcmp(lst->cmd[0], "echo") == 0)
		ft_echo(envcp, 0);
	else if (ft_strcmp(lst->cmd[0], "cd") == 0)
		ft_cd(envcp);
	else if (ft_strcmp(lst->cmd[0], "pwd") == 0)
		ft_pwd();
	else if (ft_strcmp(lst->cmd[0], "export") == 0)
		ft_export(envcp, export, 0);
	else if (ft_strcmp(lst->cmd[0], "unset") == 0)
	{
		ft_unset(lst->cmd, export, 0, 0);
		ft_unset(lst->cmd, envcp, 1, 0);
	}
	else if (ft_strcmp(lst->cmd[0], "env") == 0)
		ft_env(envcp, 0);
	else if (ft_strcmp(lst->cmd[0], "exit") == 0)
		ft_exit(lst->cmd, envcp, export);
}
