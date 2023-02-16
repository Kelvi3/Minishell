/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_unset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:00:45 by lulaens           #+#    #+#             */
/*   Updated: 2023/02/15 15:32:13 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// changer le nom de fonction
int	ft_check_len(char *key, t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
//	printf("len = %ld //// %s\n", ft_strlen(key), tmp->name);
//	printf("len = %ld\n", ft_strlen(tmp->name));
	if (!ft_strchr(key, '='))
		return (0);
	while (tmp)
	{
		if (ft_strncmp(key, tmp->name, ft_strlen(tmp->name)) == 0)
		{
			if (ft_strncmp(ft_strchr(key, '=') + 1, tmp->value,
					ft_strlen(tmp->value)) == 0)
			{
				ft_putstr_fd("bash: unset: not a valid identifier\n", 2);
				return (1);
			}
		}
		tmp = tmp->next;
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
	//  FREE BUG
	//	free((*tmp)->value);
	//	free((*tmp)->name);
	}
}
