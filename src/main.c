/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 09:57:57 by tcazenav          #+#    #+#             */
/*   Updated: 2023/02/16 09:56:18 by lulaens          ###   ########.fr       */
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
	t_list		*envcp;
	t_list		*export;

	(void) argc;
	(void) argv;
	line = NULL;
	envcp = NULL;
	export = NULL;
	path = current_path();
	cmd = NULL;
	ft_signal();
	envcp = init_lst(envcp, env);
	export = init_lst(export, env);
	while (1)
	{
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
		int i = 0;
		while (cmd[i])
		{
			printf("cmd[%d] = %s\n", i, cmd[i]);
			i++;
		}
	//	if (is_pipe(cmd) == 1)
	//		parse_pipe(cmd, env);
		/*exec = is_executable(cmd[0], env);
		if (exec != NULL)
			printf("%s\n", exec);*/
		if (is_pipe(cmd) == 1)
			parse_pipe(cmd, env);
		ft_check_line(line);
		ft_builtins(cmd, env, &envcp, &export);
		if (line)
			add_history(line);
		free_double_char(cmd);
		free(line);
		line = NULL;
	}
	free_lst(&envcp);
	free_lst(&export);
//	free(path);
	return (0);
}
