/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   current_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:40:05 by tcazenav          #+#    #+#             */
/*   Updated: 2023/02/03 13:15:10 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	*build_current_path(char *cwd, int i)
{
	char	*path;
	int		z;

	z = 0;
	while (cwd[i] != '\0')
	{
		i++;
		z++;
	}
	path = malloc(sizeof(char) * (z + 1));
	if (!path)
		return (NULL);
	i -= z;
	z = 0;
	while (cwd[i] != '\0')
	{
		path[z] = cwd[i];
		z++;
		i++;
	}
	return (path);
}

static char	*split_path_name(char *cwd)
{
	int		i;
	int		z;
	char	*user;
	char	*path;

	i = 0;
	z = 0;
	user = getenv("USER");
	while (cwd[i] != '\0' && user[z] != '\0')
	{
		z = 0;
		while (cwd[i] == user[z])
		{
			i++;
			z++;
			if (user[z] == '\0')
				break ;
		}
		if (user[z] != '\0')
			i++;
	}
	path = build_current_path(cwd, i);
	return (path);
}

char	*current_path(void)
{
	char	cwd[256];
	char	*path;

	path = NULL;
	if (chdir("./") != 0)
		perror("error: ");
	else
	{
		if (getcwd(cwd, sizeof(cwd)) == NULL)
			perror("error: ");
		else
			path = split_path_name(cwd);
	}
	return (path);
}
