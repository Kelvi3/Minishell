/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:28:05 by lulaens           #+#    #+#             */
/*   Updated: 2023/02/17 13:32:07 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// chemin absolu : depuis la racine ~
// chemin relatif : depuis le repertoire courant
// manque : cd ~../
void	ft_cd(char **cmd, char **env)
{
	if (ft_len(cmd) > 2)
	{	
		g_exit_code = 1;
		ft_putstr_fd("cd : too many arguments\n", 2);
	}
	if (access(cmd[1], F_OK) == -1)
	{
		g_exit_code = 1;
		ft_putstr_fd("cd : No such file or directory\n", 2);
	}
	if (ft_len(cmd) == 1 || (ft_len(cmd) == 2 && cmd[1][0] == '~'
		&& ft_strlen(cmd[1]) == 0))
	{
		if (env)
		{
			if (chdir(getenv("HOME")) == -1)
				ft_putstr_fd("cd : No such file or directory\n", 2);
		}
	}
	else
	{
		if (cmd[1] && env)
		{
			if (chdir(cmd[1]) == -1)
				ft_putstr_fd("cd : No such file or directory\n", 2);
		}
	}
}
