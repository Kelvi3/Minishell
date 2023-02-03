/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 09:57:57 by tcazenav          #+#    #+#             */
/*   Updated: 2023/02/03 15:22:04 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <string.h>
#include <unistd.h>

int	main(int argc, char **argv, char **env)
{
	char		*path;
	char		*line;
	char		**cmd;
	int			i;

	(void) argc;
	(void) argv;
	(void) env;
	line = NULL;
	path = current_path();
	cmd = NULL;
	ft_signal();
	while (1)
	{
		line = readline("$>");
		if (line == NULL)
			break ;
		cmd = parse_cmd(line, cmd);
		ft_builtins(cmd, env);
		add_history(line);
	}
	i = 0;
/*	while (cmd[i] != NULL)
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);*/
	free(line);
	free(path);
	return (0);
}
