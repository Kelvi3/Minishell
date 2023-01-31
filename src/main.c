/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 09:57:57 by tcazenav          #+#    #+#             */
/*   Updated: 2023/01/31 11:38:40 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <readline/history.h>
#include <readline/readline.h>

int	main(void)
{
	char	*path;
	char	*line;

	line = NULL;
	path = current_path();
	ft_signal();
	while (1)
	{
		line = readline(">$");
		add_history(line);
		ft_check_line(line);
		printf("%s", line);
	}
	free(path);
	return (0);
}
