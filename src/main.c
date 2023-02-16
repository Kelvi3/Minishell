/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 09:57:57 by tcazenav          #+#    #+#             */
/*   Updated: 2023/02/16 10:41:18 by tcazenav         ###   ########.fr       */
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
	i = 0;
	while (1)
	{
		i = 0;
		line = readline("$>");
		if (line == NULL)
			break ;
		cmd = parse_cmd(line, cmd);
		// voir probleme avec export
//		if (cmd[0])
//			ft_builtins(cmd, env);
	/*	while (cmd[i])
		{
			printf("cmd[%d] = %s\n", i, cmd[i]);
			i++;
		}*/
		printf("cmd[0] = %s \n cmd[1] = %s\n", cmd[0], cmd[1]);
	//	if (is_pipe(cmd) == 1)
	//		parse_pipe(cmd, env);
		/*exec = is_executable(cmd[0], env);
		if (exec != NULL)
			printf("%s\n", exec);*/
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
