/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 09:57:57 by tcazenav          #+#    #+#             */
/*   Updated: 2023/01/31 14:10:23 by tcazenav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <readline/readline.h>

int	main(void)
{
	char		*path;
	char		*line;

	line = NULL;
	path = current_path();
	while (1)
	{
		line = readline("$>");
		parse_cmd(line);
		free(line);
		line = NULL;
	}
	free(line);
	free(path);
	return (0);
}
