/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:28:05 by lulaens           #+#    #+#             */
/*   Updated: 2023/02/20 09:47:53 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <stdlib.h>
#include <unistd.h>

// chemin absolu : depuis la racine ~
// chemin relatif : depuis le repertoire courant
// manque : cd ~../
void	ft_cd(char **cmd, t_list **envcp)
{
	if (ft_len(cmd) > 2)
	{	
		g_exit_code = 1;
		ft_putstr_fd("cd : too many arguments\n", 2);
		return ;
	}
	/* recup var $ */
	if (ft_strncmp(cmd[1], "$", 1) == 0)
	{
		g_exit_code = 0;
	//	printf("%s\n", ft_check_doll(cmd, envcp));
		if(chdir(ft_check_doll(cmd, envcp, 1)) == -1)
			ft_putstr_fd("cd : No such file or directory\n", 2);
		return ;
	}
	if (access(cmd[1], F_OK) == -1)
	{
		g_exit_code = 1;
		ft_putstr_fd("cd : No such file or directory\n", 2);
		return ;
	}
	if (ft_len(cmd) == 1 || (ft_len(cmd) == 2 && cmd[1][0] == '~'
		&& ft_strlen(cmd[1]) == 0))
	{
		if (chdir(getenv("HOME")) == -1)
			ft_putstr_fd("cd : No such file or directory\n", 2);
		return ;
	}
	else
	{
		if (cmd[1])
		{
			if (chdir(cmd[1]) == -1)
				ft_putstr_fd("cd : No such file or directory\n", 2);
			return ;
		}
	}
}
