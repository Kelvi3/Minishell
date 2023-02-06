/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:51:31 by lulaens           #+#    #+#             */
/*   Updated: 2023/02/03 15:10:02 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <unistd.h>

void	ft_builtins(char **cmd, char **env)
{
	if (ft_strncmp(cmd[0], "echo", 4) == 0)
		ft_echo(cmd);
	if (ft_strncmp(cmd[0], "cd", 2) == 0)
		ft_cd(cmd);
	if (ft_strncmp(cmd[0], "pwd", 3) == 0)
		ft_pwd(cmd);
	if (ft_strncmp(cmd[0], "export", 6) == 0)
		ft_export(env, cmd);
//	if (ft_strncmp(cmd[0], "unset", 5) == 0)
//		ft_unset();
	if (ft_strncmp(cmd[0], "env", 3) == 0)
		ft_env(env, cmd);
	if (ft_strncmp(cmd[0], "exit", 4) == 0)
		ft_exit(cmd);
}
