/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:51:49 by lulaens           #+#    #+#             */
/*   Updated: 2023/02/02 09:40:50 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_pwd(char **cmd)
{
	char	*line;

	if (ft_len(cmd) > 1)
		ft_putstr_fd("pwd : too many arguments\n", 2);
	line = malloc(sizeof(char) * (PATH_MAX + 1));
	line[PATH_MAX + 1] = '\0';
	line = getcwd(line, PATH_MAX);
	if (line == NULL)
		ft_putstr_fd("Error getcwd\n", 2);
	printf("%s\n", line);
	free(line);
}
