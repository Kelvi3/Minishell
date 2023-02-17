/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:51:49 by lulaens           #+#    #+#             */
/*   Updated: 2023/02/17 11:26:38 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_pwd(char **cmd)
{
	char	*line;

	(void)cmd;
	g_exit_code = 0;
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
