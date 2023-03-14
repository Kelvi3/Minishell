/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_var_env_echo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:54:03 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/10 14:50:13 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	*search_varrr(t_data **envcp, int len_var, int start, int i)
{
	t_data	*lst;
	char	*var;
	char	*value;

	value = NULL;
	lst = *envcp;
	var = NULL;
	var = ft_substr(lst->cmd[i], start - 1, len_var);
	while (lst->envcp->next)
	{
		if (ft_strcmp(lst->envcp->name, var) == 0)
		{
			free(var);
			value = ft_strdup(lst->envcp->value);
			if (value)
				return (value);
		}
		lst->envcp = lst->envcp->next;
	}
	if (ft_strcmp(lst->envcp->name, var) == 0)
	{
		free(var);
		value = ft_strdup(lst->envcp->value);
		if (value)
			return (value);
	}
	free(var);
	return (NULL);
}

void	cpy_var_env(t_data *lst, int *i, int *j, int *c)
{
	int		len_var;
	int		t;
	char	*tmp1;

	tmp1 = NULL;
	t = 0;
	len_var = 0;
	if (lst->flag == 1)
		return ;
	if (lst->cmd[*i][*j] == '$' && lst->cmd[*i][*j + 1] != '?')
	{
		*j += 1;
		while (lst->cmd[*i][*j] && ft_isalpha(lst->cmd[*i][*j]))
		{
			len_var++;
			*j += 1;
		}
		tmp1 = search_varrr(&lst, len_var, *j - len_var + 1, *i);
		len_var = 0;
		if (!tmp1)
			return ;
		while (tmp1[t])
		{
			lst->echo[*c] = tmp1[t++];
			*c += 1;
		}
	}
}
