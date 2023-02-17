/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dollard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:50:00 by lulaens           #+#    #+#             */
/*   Updated: 2023/02/17 13:36:35 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_test_cpy(char *cmd)
{
	int		i;
	int		j;
	char	*name;

	i = 1;
	j = 0;
	name = malloc(sizeof(char) * (ft_strlen(cmd)) + 1);
	if (!name)
		return (NULL);
	while (cmd[i])
	{
		name[j] = cmd[i];
		j++;
		i++;
	}
	name[j] = '\0';
	return (name);
}

char	*ft_check_doll(char **cmd, t_list **envcp)
{
	int		i;
	char	*name;
	t_list	*tmp;

	i = 0;
	while (cmd[i])
	{
		tmp = *envcp;
		name = ft_test_cpy(cmd[i]);
		while (tmp)
		{
			if (ft_strncmp(name, tmp->name, ft_strlen(tmp->name)) == 0)
			{
				free(name);
				return (tmp->value);
			}
			tmp = tmp->next;
			if (!tmp)
				break ;
		}
		i++;
	}
	return (NULL);
}
