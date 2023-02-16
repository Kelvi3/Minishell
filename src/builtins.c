/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:51:31 by lulaens           #+#    #+#             */
/*   Updated: 2023/02/08 13:09:58 by tcazenav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <unistd.h>

void	ft_builtins(char **cmd, char **env)
{
	if (ft_strncmp(cmd[0], "echo", 4) == 0)
		ft_echo(cmd);
	else if (ft_strncmp(cmd[0], "cd", 2) == 0)
		ft_cd(cmd);
	else if (ft_strncmp(cmd[0], "pwd", 3) == 0)
		ft_pwd(cmd);
	else if (ft_strncmp(cmd[0], "export", 6) == 0)
		ft_export(env, cmd);
	else if (ft_strncmp(cmd[0], "env", 3) == 0)
		ft_env(env, cmd);
	else if (ft_strncmp(cmd[0], "exit", 4) == 0)
		ft_exit(cmd);
	else
		return ;
//	if (ft_strncmp(cmd[0], "unset", 5) == 0)
//		ft_unset();
}
