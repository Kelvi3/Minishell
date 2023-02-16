/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:18:25 by lulaens           #+#    #+#             */
/*   Updated: 2023/02/16 10:24:04 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"
#include <string.h>

int	ft_check_name(char **args)
{
	int	i;
	int	j;

	i = 1;
	while (args[i])
	{
		j = 0;
		if (ft_isalpha(args[i][0]) == 0 && args[i][0] != '_')
			return (1);
		while (args[i][j] && args[i][j] != '=')
		{
			if (ft_isalnum(args[i][j]) == 0 && args[i][j] != '_')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static	int	ft_add_value(t_list *tmp, t_list *tmp1, char *args, char *name)
{
	if (ft_strncmp(args, tmp->name, ft_strlen(name)) == 0)
	{
		if (!ft_strchr(args, '='))
			return (1);
		tmp->value = ft_cpy_value(args);
		tmp1->value = ft_cpy_value(args);
		return (1);
	}
	return (0);
//	free(name);
}

int	ft_check_double(t_list *export, t_list *envcp, char **args)
{
	int		i;
	char	*name;
	t_list	*tmp;
	t_list	*tmp1;

	tmp = export;
	tmp1 = envcp;
	i = 1;
	while (args[i])
	{
		tmp = export;
		name = ft_cpy_name(args[i]);
		while (tmp)
		{
			if (ft_add_value(tmp, tmp1, args[i], name) == 1)
				return (1);
			tmp = tmp->next;
		}
		free(name);
		i++;
	}
	return (0);
}
