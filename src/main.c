/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 09:57:57 by tcazenav          #+#    #+#             */
/*   Updated: 2023/02/01 09:07:57 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **env)
{
	char		*path;
	char		*line;

	(void) argc;
	(void) argv;
	line = NULL;
	path = current_path();
	ft_signal();
	while (1)
	{
		line = readline("$>");
		parse_cmd(line);
		free(line);
		line = NULL;
		add_history(line);
		ft_check_line(line);
		printf("%s", line);
	}
	free(line);
	free(path);
	return (0);
}
