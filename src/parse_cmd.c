/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:47:12 by tcazenav          #+#    #+#             */
/*   Updated: 2023/03/02 14:05:13 by lulaens          ###   ########.fr       */
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
		if (line[i] == '<' && line[i + 1] != '<')
			return (j);
		i++;
		j++;
	}
	if (line[i] != ' ' && line[i] != 39 && line[i] != '"' && line[i] != '\0'
		&& line[i] != '<')
	{
		printf("Syntaxe: error\n");
		return (-1);
	}
	if (j == 1 && line[i] != '<')
		return (0);
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
	while (tmp->line && tmp->line[i] != '\0')
	{
		len = ft_sep(tmp->line, i, len);
		if (len == -1)
			return ;
		word++;
		if (len == 0)
			i++;
		i = i + len;
	}
	parse_cmd_bis(lst, word);
}
