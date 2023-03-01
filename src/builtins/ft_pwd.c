/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:51:49 by lulaens           #+#    #+#             */
/*   Updated: 2023/02/22 11:36:57 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <stdlib.h>

int	check_var_pwd(t_list **envcp)
{
	t_list	*tmp;

	tmp = *envcp;
/*	while (tmp)
	{
		printf("test = %s\n", tmp->name);
		tmp = tmp->next;
	}*/
	while (tmp)
	{
		if (ft_strncmp(tmp->name, "PWD", 3) == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

/* Verif value de var PWD */
/*tout revoir */
void	ft_pwd(char **cmd, t_list **envcp)
{
	char	*line;

	(void) line;
	(void)cmd;
	g_exit_code = 0;
	if (check_var_pwd(envcp) == 1)
	{
		ft_putstr_fd("Error variable PWD no exist\n", 2);
		return ;
	}
	else
	{
		line = malloc(sizeof(char) * (PATH_MAX + 1));
		if (!line)
			return ;
		line[PATH_MAX + 1] = '\0';
		line = getcwd(line, PATH_MAX);
		if (line == NULL)
			ft_putstr_fd("Error getcwd\n", 2);
		printf("%s\n", line);
		if (line)
			free(line);
	}
}
