/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_var_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:50:00 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/01 10:33:54 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_nb_dol(char *cmd)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '$')
			c++;
		i++;
	}
	return (c);
}

char	*ft_test_cpy(char *cmd, int i)
{
	int		j;
	char	*name;

	j = 0;
	name = malloc(sizeof(char) * (ft_strlen(cmd)) + 1);
	if (!name)
		return (NULL);
	while (cmd[i] && cmd[i] != '$')
	{
		name[j] = cmd[i];
		j++;
		i++;
	}
	name[j] = '\0';
	return (name);
}

char	*ft_check_doll(char **cmd, t_list **envcp, int j)
{
	size_t		i;
	char		*value;
	char		*name;
	t_list		*tmp;

	i = 0;
	value = NULL;
	while (i < ft_strlen(cmd[j]))
	{
		if (cmd[j][i] == '$')
		{
			i++;
			name = ft_test_cpy(cmd[j], i);
			tmp = *envcp;
			while (tmp)
			{
				if (ft_strncmp(name, tmp->name, ft_strlen(tmp->name)) == 0)
				{
					if (!value)
						value = ft_strdup(tmp->value);
					else
						value = ft_strjoin(value, tmp->value);
					break ;
				}
				tmp = tmp->next;
			}
			free(name);
		}
		i++;
	}
	return (value);
}
