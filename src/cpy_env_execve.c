/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_env_execve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:40:48 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/14 10:16:27 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/* envoyer copy de env et pas export en paramtre */

static char	*cpy(char **envcpy, t_data *lst, int i)
{
	envcpy[i] = ft_strdup(lst->envcp->name);
	envcpy[i] = ft_strjoin(envcpy[i], "=");
	if (lst->envcp->value)
		envcpy[i] = ft_strjoin(envcpy[i], lst->envcp->value);
	return (envcpy[i]);
}

char	**cpy_env_execve(t_data	*data)
{
	char	**envcpy;
	int		i;

	i = 0;
	envcpy = NULL;
	if (envcpy)
		free_double_char(envcpy);
	envcpy = malloc(sizeof(char *) * (ft_lst_size(data->envcp) + 1));
	if (!envcpy)
		return (NULL);
	envcpy[i] = cpy(envcpy, data, i);
	i++;
	data->envcp = data->envcp->next;
	while (data->envcp)
	{
		envcpy[i] = cpy(envcpy, data, i);
		i++;
		data->envcp = data->envcp->next;
	}
	envcpy[i] = NULL;
	return (envcpy);
}
