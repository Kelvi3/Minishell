/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_unset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:00:45 by lulaens           #+#    #+#             */
/*   Updated: 2023/02/22 11:29:11 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_check_unset_arg(char *key, int flag)
{
	int	i;

	i = 0;
	while (key[i])
	{
		if (key[i] == '=')
		{
			if (flag == 0)
			{
				ft_putstr_fd("bash: unset: ", 2);
				ft_putstr_fd(key, 2);
				ft_putstr_fd(" not a valid identifier\n", 2);
			}
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_check_lst_name(char *key, t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		if (ft_strncmp(key, tmp->name, ft_strlen(tmp->name)) == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_swp(t_list **tmp, t_list **t_tmp, int flag)
{
	if (flag == 0)
	{
		*t_tmp = (*tmp)->next;
		(*tmp)->next = (*t_tmp)->next;
	}
	else if (flag == 1)
	{
		(*tmp)->value = (*tmp)->next->value;
		(*tmp)->name = (*tmp)->next->name;
		*t_tmp = (*tmp)->next;
		(*tmp)->next = (*t_tmp)->next;
	}
}
