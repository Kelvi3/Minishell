/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:51:31 by lulaens           #+#    #+#             */
/*   Updated: 2023/02/16 09:30:57 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <readline/history.h>
#include <unistd.h>

void	ft_builtins(char **cmd, char **env, t_list **envcp, t_list **export)
{
	if (ft_strncmp(cmd[0], "echo", 4) == 0) // parsing a faire et tt le reste
		ft_echo(cmd);
	else if (ft_strncmp(cmd[0], "cd", 2) == 0) // ok
		ft_cd(cmd, env);
	else if (ft_strncmp(cmd[0], "pwd", 3) == 0 ) // ok
		ft_pwd(cmd);
	else if (ft_strncmp(cmd[0], "export", 6) == 0)
		ft_export(cmd, envcp, export);
	else if (ft_strncmp(cmd[0], "unset", 5) == 0) // void len du name + unset 2 fois le premier
	{
		ft_unset(cmd, export);
		ft_unset_env(cmd, envcp);
	}
	else if (ft_strncmp(cmd[0], "env", 3) == 0) // voir le sort ascii export
		ft_env(envcp, cmd);
	else if (ft_strncmp(cmd[0], "exit", 4) == 0) // ok
		ft_exit(cmd, envcp, export);
}
