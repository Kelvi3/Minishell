/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:28:05 by lulaens           #+#    #+#             */
/*   Updated: 2023/02/02 11:33:51 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// chemin absolu : depuis la racine ~
// chemin relatif : depuis le repertoire courant

void	ft_cd(char **cmd)
{
	if (ft_len(cmd) > 2)
		ft_putstr_fd("cd : too many arguments\n", 2);
	if (access(cmd[1], F_OK) == -1)
		ft_putstr_fd("cd : No such file or directory\n", 2);
	else
	{
		if (chdir(cmd[1]) == -1)
			ft_putstr_fd("cd : No such file or directory\n", 2);
	}
}
