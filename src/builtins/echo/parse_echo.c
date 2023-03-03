/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:54:03 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/02 15:15:24 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

/* parse cmd echo example: "echo" */

static int	dquote(char *line, int dc, int i)
{
	while (line[i] && line[i] != ' ')
	{
		if (line[i] == '"')
			dc++;
		if (line[i] == '\'')
			return (0);
		i++;
	}
	if (dc % 2 != 0)
		return (0);
	return (i);
}

/* parse cmd echo example: 'echo' */

static int	squote(char *line, int c, int i)
{
	while (line[i] && line[i] != ' ')
	{
		if (line[i] == '\'')
			c++;
		if (line[i] == '"' || line[i] == ' ')
			return (0);
		i++;
	}
	if (c % 2 != 0)
		return (0);
	return (i);
}

/* check single cote double cote and no cote */

int	check_cote_echo(char *line)
{
	int	i;
	int	c;
	int	dc;

	dc = 0;
	c = 0;
	i = 0;
	if (line[0] == '"')
		i = dquote(line, dc, i);
	else if (line[0] == '\'')
		i = squote(line, c, i);
	else
	{
		while (line[i] && line[i] != ' ')
		{
			if (line[i] == '\'')
				c++;
			if (line[i] == '"')
				dc++;
			i++;
		}
	}
	if (dc % 2 != 0 || c % 2 != 0)
		return (0);
	return (i);
}

/* check param echo -n */

int	ft_check_n(char *cmd)
{
	int	i;

	i = 1;
	if (cmd[0] == '-' && cmd[1] == 'n')
	{
		while (cmd[i])
		{
			if (cmd[i] != 'n')
				return (1);
			i++;
		}
	}
	else
		return (1);
	return (0);
}

/* pass after -n */

int	ft_pass_n(char *line, int i)
{
	while (line[i] && line[i] == ' ')
		i++;
	while (line[i] && (line[i] == '"' || line[i] == '\''))
		i++;
	i++;
	while (line[i] && line[i] == 'n')
		i++;
	while (line[i] && (line[i] == '"' || line[i] == '\''))
		i++;
	while (line[i] && line[i] == ' ')
		i++;
	return (i);
}
