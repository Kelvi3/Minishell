/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 09:57:57 by tcazenav          #+#    #+#             */
/*   Updated: 2023/02/06 11:28:36 by tcazenav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **env)
{
	char		*path;
	char		*line;
	char		**cmd;
	int			i;

	i = 0;
	(void) argc;
	(void) argv;
	line = NULL;
	path = current_path();
	cmd = NULL;
	ft_signal();
	while (1)
	{
		line = readline("$>");
		cmd = parse_cmd(line, cmd);
		printf("cmd[0] = %s / cmd[1] = %s\n", cmd[0], cmd[1]);
		if (is_pipe(cmd) == 1)
			parse_pipe(cmd, env);
		/*exec = is_executable(cmd[0], env);
		if (exec != NULL)
			printf("%s\n", exec);*/
		add_history(line);
		ft_check_line(line);
		free(line);
		line = NULL;
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
