/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:51:31 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/14 10:59:01 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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

void	ft_builtins(t_data **data)
{
	t_data *lst;

	lst = *data;
	if (ft_strcmp(lst->cmd[0], "echo") == 0)
		ft_echo(&lst);
	else if (ft_strcmp(lst->cmd[0], "cd") == 0)
		ft_cd(&lst);
	else if (ft_strcmp(lst->cmd[0], "pwd") == 0)
		ft_pwd();
	else if (ft_strcmp(lst->cmd[0], "export") == 0)
		ft_export(data);
	else if (ft_strcmp(lst->cmd[0], "unset") == 0)
	{
		ft_unset(lst->cmd, &lst->export, 0, &lst);
		ft_unset(lst->cmd, &lst->envcp, 1, &lst);
	}
	else if (ft_strcmp(lst->cmd[0], "env") == 0)
		ft_env(&lst);
	else if (ft_strcmp(lst->cmd[0], "exit") == 0)
		ft_exit(lst->cmd, &lst->envcp, &lst->export);
}
