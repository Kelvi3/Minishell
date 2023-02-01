/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 09:57:57 by tcazenav          #+#    #+#             */
/*   Updated: 2023/02/01 14:22:21 by tcazenav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <readline/history.h>
#include <readline/readline.h>

int	main(void)
{
	char		*path;
	char		*line;
	char		**cmd;
	int			i;

	i = 0;
	path = current_path();
	line = NULL;
	cmd = NULL;
	//ft_signal();
	while (1)
	{
		i = 0;
		line = readline("$>");
		cmd = parse_cmd(line, cmd);
		free(line);
		line = NULL;
		add_history(line);
		//ft_check_line(line);
	}
	i = 0;
	while (cmd[i] != NULL)
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
	free(line);
	free(path);
	return (0);
}
