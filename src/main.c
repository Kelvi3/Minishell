/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 09:57:57 by tcazenav          #+#    #+#             */
/*   Updated: 2023/02/02 16:27:11 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <string.h>
#include <unistd.h>

int	main(int argc, char **argv, char **env)
{
	char		*path;
	char		*line;

	(void) argc;
	(void) argv;
	(void) env;
	line = NULL;
//	path = current_path();
	ft_signal();
	while (1)
	{
		line = readline("$>");
		ft_check_line(line);
	//	parse_cmd(line);
		if (ft_strncmp(line, "export", 6) == 0)
			ft_export(env);
		free(line);
		line = NULL;
		add_history(line);
		printf("%s", line);
	}
	free(line);
	free(path);
	return (0);
}
