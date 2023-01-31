/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 09:57:57 by tcazenav          #+#    #+#             */
/*   Updated: 2023/01/31 10:54:53 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <readline/readline.h>

static char	*get_prompt(void)
{
	char	*prompt;
	prompt = ft_strdup("\e[1;36mminishell$>\x1B[0m");
	return (prompt);
}

int	main(void)
{
	char	*path;
	char	*line;
	char	*prompt;

	line = NULL;
	path = current_path();
	while (1)
	{
		prompt = get_prompt();
		line = readline(prompt);
		free(prompt);
		printf("%s", line);
	}
	free(path);
	return (0);
}
