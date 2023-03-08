/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:47:12 by tcazenav          #+#    #+#             */
/*   Updated: 2023/03/08 13:36:44 by tcazenav         ###   ########.fr       */
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
	while (line[i] != ' ' && line[i] != '\0')
	{
		if ((line[i] == '<' && line[i + 1] != '<')
			|| (line[i] == '>' && line[i + 1] != '>'))
		{
			return (j);
		}
		if (line[i + 1] == '|' && line[i + 1] != ' ')
		{
			j++;
			return (j);
		}
		i++;
		j++;
	}
	/*if (line[i] != ' ' && line[i] != 39 && line[i] != '"' && line[i] != '\0'
		&& line[i] != '<' && line[i] != '>')
	{
		printf("Syntaxe: error\n");
		return (-1);
	}
	if (j == 1 && line[i] != '<')
		return (0);*/
	return (j);
}

void	parse_cmd(t_list **lst)
{
	int			i;
	int			word;
	int			len;
	t_list		*tmp;

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
		word++;
		if (len == 0)
			i++;
		i = i + len;
	}
	printf("word = %i\n", word);
	parse_cmd_bis(lst, word);
}
