/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:28:05 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/10 14:45:11 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <stdlib.h>
#include <unistd.h>

// chemin absolu : depuis la racine ~
// chemin relatif : depuis le repertoire courant
// manque : cd ~../
void	ft_cd(t_data **envcp)
{
	t_data	*lst;

	lst = *envcp;
	if (ft_len(lst->cmd) > 2)
	{	
		g_exit_code = 1;
		ft_putstr_fd("cd : too many arguments\n", 2);
		return ;
	}
	if (ft_strncmp(lst->cmd[1], "$", 1) == 0)
	{
		g_exit_code = 0;
		if(chdir(ft_doll_env(lst->cmd, envcp, 1)) == -1)
			ft_putstr_fd("cd : No such file or directory\n", 2);
		return ;
	}
	if (access(lst->cmd[1], F_OK) == -1)
	{
		g_exit_code = 1;
		ft_putstr_fd("cd : No such file or directory\n", 2);
		return ;
	}
	if (ft_len(lst->cmd) == 1 || (ft_len(lst->cmd) == 2
			&& lst->cmd[1][0] == '~'
		&& ft_strlen(lst->cmd[1]) == 0))
	{
		if (chdir(getenv("HOME")) == -1)
			ft_putstr_fd("cd : No such file or directory\n", 2);
		return ;
	}
	else
	{
		if (lst->cmd[1])
		{
			if (chdir(lst->cmd[1]) == -1)
				ft_putstr_fd("cd : No such file or directory\n", 2);
			return ;
		}
	}
}
