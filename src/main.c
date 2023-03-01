/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:59:33 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/01 16:50:19 by tcazenav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <string.h>
#include <unistd.h>

int	g_exit_code = 0;

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
		if (line[0] != '\0')
		{
			cmd = parse_cmd(line, cmd);
			if (is_pipe(cmd) == 1)
				parse_pipe(cmd, env);
			ft_check_line(line, envcp, export);
			ft_builtins(cmd, line, &envcp, &export);
			if (line)
				add_history(line);
			free_double_char(cmd);
			free(line);
			line = NULL;
		}
	}
/* probleme double free export hello*/
//	free_lst(&envcp);
//	free_lst(&export);
	free(path);
	return (0);
}
