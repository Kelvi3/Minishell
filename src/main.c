/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 09:57:57 by tcazenav          #+#    #+#             */
/*   Updated: 2023/02/03 13:43:26 by lulaens          ###   ########.fr       */
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

	i = 0;
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
		ft_check_line(line);
		cmd = parse_cmd(line, cmd);
		//if (ft_strncmp(cmd[0], "export", 6) == 0)
		//	ft_export(env);
		printf("cmd = %s\n", cmd[0]);
	//	add_history(line);
		printf("%s", line);
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
