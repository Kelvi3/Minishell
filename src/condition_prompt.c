/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_prompt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:10:13 by tcazenav          #+#    #+#             */
/*   Updated: 2023/02/03 12:55:35 by tcazenav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	is_pipex(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '|' || line[i] == '>' || line[i] == '<'
			|| (line[i] == '<' && line[i + 1] == '<'))
			return (0);
		i++;
	}
	return (1);
}

void	condition_prompt(char *line)
{
	if (is_pipex(line) == 0)
		return ;
		//pipex(line);
}
