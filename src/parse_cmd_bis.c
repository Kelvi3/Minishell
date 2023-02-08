/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 07:59:06 by tcazenav          #+#    #+#             */
/*   Updated: 2023/02/08 10:44:15 by tcazenav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	ft_count_size(char *line, int len, int i)
{
	int		size;

	size = i;
	if (len == 1)
		return (len);
	while (line[size] && line[size] != ' ')
	{
		if (line[size] == '"' || line[size] == 39)
			len--;
		size++;
	}
	if (line[size] == ' ')
		len--;
	return (len);
}

static char	*ft_inc(char *cmd, int len, char *line, int i)
{
	int		j;

	len = ft_count_size(line, len, i);
	cmd = malloc(sizeof(char) * (len + 1));
	if (!cmd)
		return (NULL);
	j = 0;
	while (j < len)
	{
		if (line[i] != '"' && line[i] != 39)
		{
			cmd[j] = line[i];
			j++;
		}
		i++;
	}
	cmd[j] = '\0';
	return (cmd);
}

int	ft_sep(char *line, int i, int len)
{
	if (line[i] == 39)
		len = count_squote(line, i);
	else if (line[i] == '"')
		len = count_dquote(line, i);
	else
		len = count_no_delim(line, i);
	return (len);
}

static int	count_len(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	return (i);
}

char	**parse_cmd_bis(char **cmd, char *line, int word)
{
	int			i;
	int			len;

	len = 0;
	cmd = malloc(sizeof(char *) * (word + 1));
	if (!cmd)
		return (NULL);
	word = 0;
	i = count_len(line);
	while (line[i] != '\0')
	{
		len = ft_sep(line, i, len);
		if (len == -1)
			return (NULL);
		if (len == 0)
			i++;
		if (len != 0)
		{
			cmd[word] = ft_inc(cmd[word], len, line, i);
			word++;
		}
		i = i + len;
	}
	cmd[word] = NULL;
	return (cmd);
}
