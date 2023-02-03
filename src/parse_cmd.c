/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:47:12 by tcazenav          #+#    #+#             */
/*   Updated: 2023/02/03 14:27:51 by tcazenav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	count_squote(char *line, int i)
{
	int	j;

	j = 1;
	i++;
	while (line[i] != ' ' && line[i] != '\0')
	{
		i++;
		j++;
		if (line[i] == 39 && line[i + 1] != ' ' && line[i + 1] != '\0')
		{	
			i += 2;
			j += 2;
		}
	}
	j++;
	if (line[i] != 39 && line[i] != '"' && line[i] != '\0')
	{
		printf("Syntaxe: error\n");
		return (-1);
	}
	return (j);
}

int	count_dquote(char *line, int i)
{
	int	j;

	i++;
	j = 1;
	while (line[i] != ' ' && line[i] != '\0')
	{
		i++;
		j++;
		if (line[i] == '"' && line[i + 1] != ' ' && line[i + 1] != '\0')
		{	
			i += 2;
			j += 2;
		}
	}
	j++;
	if (line[i] != 39 && line[i] != '"' && line[i] != '\0')
	{
		printf("Syntaxe: error\n");
		return (-1);
	}
	return (j);
}

int	count_no_delim(char *line, int i)
{
	int	j;

	j = 1;
	i++;
	while (line[i] != ' ' && line[i] != '\0')
	{
		i++;
		j++;
		if (line[i] != ' ' && line[i + 1] != ' ' && line[i + 1] != '\0')
		{
			i += 2;
			j += 2;
		}
	}
	if (line[i] != ' ' && line[i] != 39 && line[i] != '"' && line[i] != '\0')
	{
		printf("Syntaxe: error\n");
		return (-1);
	}
	return (j);
}

static int	check_quotes(char *line)
{
	int	i;
	int	c_dquote;
	int	c_squote;

	i = 0;
	c_dquote = 0;
	c_squote = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 39)
			c_squote++;
		if (line[i] == '"')
			c_dquote++;
		i++;
	}
	if (c_dquote % 2 != 0 || c_squote % 2 != 0)
	{	
		printf("Syntaxe: error\n");
		return (1);
	}
	return (0);
}

char	**parse_cmd(char *line, char **cmd)
{
	int			i;
	int			word;
	int			len;

	i = 0;
	word = 0;
	len = 0;
	if (check_quotes(line) == 1)
		return (NULL);
	while (line[i] == ' ')
		i++;
	while (line[i] != '\0')
	{
		if (line[i] == 39)
			len = count_squote(line, i);
		else if (line[i] == '"')
			len = count_dquote(line, i);
		else
			len = count_no_delim(line, i);
		if (len == -1)
			return (NULL);
		word++;
		i = i + len + 1;
	}
	cmd = parse_cmd_bis(cmd, line, word);
	return (cmd);
}
