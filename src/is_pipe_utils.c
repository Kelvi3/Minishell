/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pipe_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:02:38 by tcazenav          #+#    #+#             */
/*   Updated: 2023/03/03 09:52:07 by tcazenav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	if_in_no_out(char **cmd)
{
	int	i;
	int	redirect;

	redirect = 0;
	i = 0;
	while (cmd[i] != NULL)
	{
		if (cmd[i][0] == '<' && cmd[i][1] == '\0')
			redirect++;
		if (cmd[i][0] == '<' && cmd[i][1] != '\0')
		{
			if (check_file(cmd[i]) == 1)
			{	
				g_exit_code = 2;
				return (-1);
			}
		}
		i++;
	}
	return (redirect);
}

int	if_in_a_out(char **cmd)
{
	int	i;
	int	redirect;

	redirect = 0;
	i = 0;
	while (cmd[i] != NULL)
	{
		if ((cmd[i][0] == '<' && cmd[i][1] == '\0')
			|| (cmd[i][0] == '>' && cmd[i][1] == '\0'))
			redirect++;
		i++;
	}
	return (redirect);
}

int	found_infile(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i] != NULL)
		i++;
	i--;
	while (i > 0)
	{
		if (cmd[i][0] == '<')
		{
			if (access(cmd[i + 2], F_OK) != -1)
				return (i + 2);
			return (i + 1);
		}
		i--;
	}
	return (0);
}
