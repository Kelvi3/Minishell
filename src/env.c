/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:08:10 by lulaens           #+#    #+#             */
/*   Updated: 2023/01/31 14:12:00 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_print_env(char **env, char *line)
{
	int	i;

	i = 0;
	(void)line;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
}

void	ft_check_built_env(char **env, char *line, size_t i)
{
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == 'e' && line[i + 1] == 'n'
		&& line[i + 2] == 'v')
	{
		ft_print_env(env, line);
		i = 0;
	}
}

// "e""n""v" non check
// voir fonction strtok

void	ft_env(char **env, char *line)
{
	size_t	i;
	size_t	end;

	end = ft_strlen(line);
	i = 0;
	ft_check_built_env(env, line, i);
	if (ft_strncmp(line, "env", 3) == 0)
	{
		while (env[i])
		{
			printf("%s\n", env[i]);
			i++;
		}
	}
	i = 0;
	if ((line[i] == '"' && line[end - 1] == '"')
		|| (line[i] == 39 && line[end - 1] == 39))
	{
		i++;
		while (line[i] && line[i] == ' ')
			i++;
		if (line[i] == 'e' && line[i + 1] == 'n'
			&& line[i + 2] == 'v')
			ft_print_env(env, line);
	}
}
