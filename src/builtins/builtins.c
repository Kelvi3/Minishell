/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:51:31 by lulaens           #+#    #+#             */
/*   Updated: 2023/02/17 13:37:36 by lulaens          ###   ########.fr       */
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
int ft_check_redirection(char **cmd)
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
void	ft_builtins(char **cmd, char **env, t_list **envcp, t_list **export)
{
	if (ft_check_pipe(cmd) == 0 || ft_check_redirection(cmd) == 0)
	{
		if (ft_strncmp(cmd[0], "$", 1) == 0)
			cmd[0] = ft_strdup(ft_check_doll(cmd, envcp));
		if (ft_strncmp(cmd[0], "echo", 5) == 0) /* rien faire si pipe apres sauf redirection */
			ft_echo(cmd);
		else if (ft_strncmp(cmd[0], "cd", 3) == 0) /* rien faire si un pipe apres  */ 
			ft_cd(cmd, env);
		else if (ft_strncmp(cmd[0], "pwd", 4) == 0 ) /* rien faire si pipe apres sauf redirection */
			ft_pwd(cmd);
		else if (ft_strncmp(cmd[0], "export", 7) == 0) /* rien faire si pipe apres sauf si redirection sans argument a export */
			ft_export(cmd, envcp, export);
		else if (ft_strncmp(cmd[0], "unset", 6) == 0) /* ne rien faire si pipe apres */
		{
			ft_unset(cmd, export);
			ft_unset_env(cmd, envcp);
		}
		else if (ft_strncmp(cmd[0], "env", 4) == 0) /* rien faire si pipe apres sauf redirection */
			ft_env(envcp, cmd);
		else if (ft_strncmp(cmd[0], "exit", 5) == 0) /* rien faire si pipe apres */
			ft_exit(cmd, envcp, export);
	}
	else 
		return ;
	/* else exec les redirection si checkredirection == 1 */
}
