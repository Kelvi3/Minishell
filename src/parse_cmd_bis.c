/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 07:59:06 by tcazenav          #+#    #+#             */
/*   Updated: 2023/02/08 14:29:57 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	*ft_inc(char *cmd, int len, char *line, int i)
{
	int		j;
	int		size;

	size = i;
	while (line[size] && line[size] != ' ')
	{
		if (line[size] == '"' || line[size] == 39)
			len--;
		size++;
	}
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

char	**parse_cmd_bis(char **cmd, char *line, int word)
{
	int			i;
	int			len;

	i = 0;
	len = 0;
	cmd = malloc(sizeof(char *) * (word + 1));
	word = 0;
	if (!cmd)
		return (NULL);
	while (line[i] && line[i] == ' ')
		i++;
	while (line[i] != '\0')
	{
		len = ft_sep(line, i, len);
		if (len == -1)
			return (NULL);
		if (len != 0)
		{	
			cmd[word] = ft_inc(cmd[word], len, line, i);
			word++;
		}
		i = i + len + 1;
	}
	cmd[word] = NULL;
	return (cmd);
}
