/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:51:49 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/09 15:00:55 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <stdlib.h>

void	ft_pwd(void)
{
	char	*line;

	g_exit_code = 0;
	line = malloc(sizeof(char) * (PATH_MAX + 1));
	if (!line)
		return ;
	line[PATH_MAX] = '\0';
	line = getcwd(line, PATH_MAX);
	if (line == NULL)
		ft_putstr_fd("Error getcwd\n", 2);
	printf("%s\n", line);
	if (line)
		free(line);
}
