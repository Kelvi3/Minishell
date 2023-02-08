/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:30:39 by tcazenav          #+#    #+#             */
/*   Updated: 2023/02/07 10:35:13 by tcazenav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_strchr_cmd(char *cmd, char c)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strcat_cmd(char *s1, int size, char *s2)
{
	int		i;
	int		len;
	char	*join;

	i = 0;
	len = 0;
	join = malloc(sizeof(char) * size);
	if (!join)
		return (NULL);
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	join[i] = '/';
	i++;
	while (s2[len])
	{
		join[i] = s2[len];
		i++;
		len++;
	}
	join[i] = '\0';
	return (join);
}

char	*fix_str(char *cmd, char c)
{
	char	*str;
	int		i;

	i = 0;
	while (cmd[i] != c)
		i++;
	str = ft_calloc(sizeof(char), i + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (cmd[i] != c)
	{
		str[i] = cmd[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_strlento(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c)
		i++;
	return (i);
}
