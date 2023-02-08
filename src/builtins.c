/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:51:31 by lulaens           #+#    #+#             */
/*   Updated: 2023/02/08 16:05:11 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_builtins(char **cmd, char **env)
{
	static t_list	*envcp = NULL;

	if (envcp == NULL)
		envcp = init_lst(envcp, env);
	if (ft_strncmp(cmd[0], "echo", 4) == 0)
		ft_echo(cmd);
	else if (ft_strncmp(cmd[0], "cd", 2) == 0)
		ft_cd(cmd, env);
	else if (ft_strncmp(cmd[0], "pwd", 3) == 0)
		ft_pwd(cmd);
	else if (ft_strncmp(cmd[0], "export", 6) == 0)
		ft_export(env, cmd, envcp);
	else if (ft_strncmp(cmd[0], "unset", 5) == 0)
		envcp = ft_unset(envcp, cmd);
	else if (ft_strncmp(cmd[0], "env", 3) == 0)
		ft_env(envcp, cmd);
	else if (ft_strncmp(cmd[0], "exit", 4) == 0)
		ft_exit(cmd);
//	else
//		printf("bug\n");
}
