/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:26:51 by tcazenav          #+#    #+#             */
/*   Updated: 2023/02/07 10:35:33 by tcazenav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	*ft_check_dir(char *dir, int *i)
{
	int		j;
	int		z;
	char	*str;

	j = 0;
	z = *i;
	str = NULL;
	while (dir[z] && dir[z] != ':')
	{
		z++;
		j++;
	}
	str = ft_calloc(sizeof(char), j + 1);
	if (!str)
		return (NULL);
	z -= j;
	j = 0;
	while (dir[z] && dir[z] != ':')
		str[j++] = dir[z++];
	*i = z;
	return (str);
}

static char	*found_path(char *const *envp)
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	i = ft_strlento(envp[0], '/');
	while (envp[0][j + i] != '\0')
		j++;
	tmp = ft_calloc(sizeof(char), j + 1);
	if (!tmp)
		return (NULL);
	j = 0;
	while (envp[0][j + i] != '\0')
	{	
		tmp[j] = envp[0][j + i];
		j++;
	}
	return (tmp);
}

char	*if_dir(char *car, char *str)
{
	char	*join;
	int		len;
	int		i;
	char	*cmd;

	if (ft_strchr_cmd(str, ' ') == 1)
		cmd = fix_str(str, ' ');
	else
		cmd = fix_str(str, '\0');
	i = 0;
	join = NULL;
	len = 0;
	while (car[i])
		i++;
	while (cmd[len])
		len++;
	join = ft_strcat_cmd(car, len + i + 2, cmd);
	if (access(join, F_OK) != -1)
	{
		free(cmd);
		return (join);
	}
	free(join);
	free(cmd);
	return (NULL);
}

static int	found_inenv(char *const *envp)
{
	int	z;

	z = 0;
	while (*envp[z])
	{
		if (envp[z][0] == 'P' && envp[z][1] == 'A' && envp[z][2] == 'T'
				&& envp[z][3] == 'H')
			break ;
		z++;
	}
	return (z);
}

char	*check_cmd(char *cmd, char *const *envp)
{
	char	*car;
	char	*dir;
	int		i;
	char	*s;

	i = found_inenv(envp);
	dir = found_path(&envp[i]);
	i = 0;
	s = NULL;
	while (dir[i] != '\0')
	{
		car = ft_check_dir(dir, &i);
		s = if_dir(car, cmd);
		free(car);
		car = NULL;
		if (s != NULL)
			break ;
		if (dir[i] != '\0')
			i++;
	}
	free(dir);
	return (s);
}
