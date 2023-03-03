/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 07:59:06 by tcazenav          #+#    #+#             */
/*   Updated: 2023/03/03 13:51:28 by tcazenav         ###   ########.fr       */
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
		if ((line[i] == '"' && line[size] == line[i])
			|| (line[i] == 39 && line[size] == line[i]))
			len--;
		size++;
	}
	if (line[size] == ' ' || line[size] == '\0')
		len--;
	return (len);
}

static char	*ft_inc(char *cmd, int len, char *line, int i)
{
	int		j;
	char	c;

	len = ft_count_size(line, len, i);
	cmd = malloc(sizeof(char) * (len + 1));
	if (!cmd)
		return (NULL);
	j = 0;
	if (line[i] == '"')
		c = '"';
	else if (line[i] == 39)
		c = 39;
	else
		c = '\0';
	while (j < len)
	{
		if (line[i] != c)
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

void	parse_cmd_bis(t_list **lst, int word)
{
	int			i;
	int			len;
	t_list		*tmp;

	len = 0;
	tmp = *lst;
	tmp->cmd = malloc(sizeof(char *) * (word + 1));
	if (!tmp->cmd)
		return ;
	word = 0;
	i = count_len(tmp->line);
	while (tmp->line && tmp->line[i] != '\0')
	{
		len = ft_sep(tmp->line, i, len);
		if (len == -1)
			return ;
		if (len == 0)
			i++;
		if (len != 0)
			tmp->cmd[word] = ft_inc(tmp->cmd[word], len, tmp->line, i);
		if (len != 0)
			word++;
		i = i + len;
	}
	tmp->cmd[word] = NULL;
}
