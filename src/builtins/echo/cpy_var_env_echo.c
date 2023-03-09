/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_var_env_echo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:54:03 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/09 10:25:19 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	*search_varrr(t_list **envcp, int len_var, int start, int i)
{
	t_list	*lst;
	char	*var;
	char	*value;

	value = NULL;
	lst = *envcp;
	var = NULL;
	var = ft_substr(lst->cmd[i], start - 1, len_var);
	while (lst->next)
	{
		if (ft_strcmp(lst->name, var) == 0)
		{
			free(var);
			value = ft_strdup(lst->value);
			if (value)
				return (value);
		}
		lst = lst->next;
	}
	if (ft_strcmp(lst->name, var) == 0)
	{
		free(var);
		value = ft_strdup(lst->value);
		if (value)
			return (value);
	}
	free(var);
	return (NULL);
}

void	cpy_var_env(t_list *lst, int *i, int *j, int *c)
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
