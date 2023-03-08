/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 07:59:06 by tcazenav          #+#    #+#             */
/*   Updated: 2023/03/08 09:36:47 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	ft_count_size(t_list **lst, int len, int i)
{
	int		size;
	int		len_var;
	t_list	*tmp;

	tmp = *lst;
	size = i;
	len_var = 0;
	if (len == 1)
		return (len);
	while (tmp->line[size] && tmp->line[size] != ' ')
	{
		if ((tmp->line[i] == '"' && tmp->line[size] == tmp->line[i])
			|| (tmp->line[i] == 39 && tmp->line[size] == tmp->line[i]))
			len--;
		size++;
	}
	if ((tmp->line[size] == ' ') || (tmp->line[i] != '"' && tmp->line[i] != 39))
		len--;
	return (len);
}

static char	*ft_inc(char *cmd, int len, t_list **lst, int i)
{
	int		j;
	char	c;
	t_list	*tmp;

	tmp = *lst;
	len = ft_count_size(lst, len, i);
	tmp->flag = 0;
	cmd = malloc(sizeof(char) * (len + 1));
	if (!cmd)
		return (NULL);
	j = 0;
	if (tmp->line[i] == '"')
	{	
		c = '"';
		tmp->flag = 2;
	}
	if (tmp->line[i] == 39)
	{	
		c = 39;
		tmp->flag = 1;
	}
	if (tmp->line[i] == '\0')
		c = '\0';
	while (j < len)
	{
		if (tmp->line[i] != c)
		{
			cmd[j] = tmp->line[i];
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
			tmp->cmd[word] = ft_inc(tmp->cmd[word], len, lst, i);
		if (len != 0)
			word++;
		i = i + len;
	}
	tmp->cmd[word] = NULL;
}
