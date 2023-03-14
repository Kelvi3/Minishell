/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:47:12 by tcazenav          #+#    #+#             */
/*   Updated: 2023/03/14 10:39:12 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	count_squote(char *line, int i)
{
	int	j;

	j = 1;
	i++;
	while (line[i] != 39 && line[i] != '\0')
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
	return (j);
}

int	count_dquote(char *line, int i)
{
	int	j;

	i++;
	j = 1;
	while (line[i] != '"' && line[i] != '\0')
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
	if (line[i] != 39 && line[i] != '"' && line[i] != '\0' && line[i] != ' ')
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
	if (line[i] == '|')
		return (1);
	while (line[i] != ' ' && line[i] != '\0')
	{
		if ((line[i] == '<' && line[i + 1] != '<')
			|| (line[i] == '>' && line[i + 1] != '>'))
			return (j);
		if (line[i + 1] == '|' && line[i] != ' ')
			return (j + 1);
		i++;
		j++;
	}
	if (line[i] != ' ' && line[i] != 39 && line[i] != '"' && line[i] != '\0'
		&& line[i] != '<' && line[i] != '>')
	{
		printf("Syntaxe: error\n");
		return (-1);
	}
	return (j - 1);
}

void	parse_cmd(t_data **lst)
{
	int			i;
	int			word;
	int			len;
	t_data		*tmp;

	tmp = *lst;
	i = 0;
	word = 0;
	len = 0;
	while (tmp->line[i] && tmp->line[i] == ' ')
		i++;
	while (ft_strlento(tmp->line, '\0') > i)
	{
		len = ft_sep(tmp->line, i, len);
		if (len == -1)
			return ;
		if (len != 0)
			word++;
		if (len != 0)
			i++;
		i = i + len;
		if (len > 1 && tmp->line[i - 1] == '|'
			&& count_squote(tmp->line, i) == count_dquote(tmp->line, i))
			i--;
		if (tmp->line[i] == ' '
			&& count_squote(tmp->line, i) == count_dquote(tmp->line, i))
			i++;
	}
//	printf("word = %i\n", word);
	parse_cmd_bis(lst, word);
}
