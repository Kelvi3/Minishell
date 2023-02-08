/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 09:57:57 by tcazenav          #+#    #+#             */
/*   Updated: 2023/02/08 11:17:28 by tcazenav         ###   ########.fr       */
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
	line = NULL;
	path = current_path();
	cmd = NULL;
	ft_signal();
	while (1)
	{
		i = 0;
		line = readline("$>");
		if (line == NULL)
			break ;
		cmd = parse_cmd(line, cmd);
		if (cmd[0] && line)
			ft_builtins(cmd, env);
		if (is_pipe(cmd) == 1)
			parse_pipe(cmd, env);
		ft_check_line(line);
		ft_builtins(cmd, env);
		add_history(line);
		free_double_char(cmd);
		free(line);
		line = NULL;
	}
	free(path);
	return (0);
}
