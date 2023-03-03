/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:28:11 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/01 16:58:05 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* probleme de len premiere fonction */

void	swap_unset_args(char *key, t_list *tmp, t_list *t_tmp)
{
//	if (tmp->next == NULL)
//		return ;
	while (ft_strcmp(key, tmp->next->name) != 0
		&& ft_strcmp(key, tmp->name) != 0)
		tmp = tmp->next;
	if (ft_strncmp(key, tmp->next->name, ft_strlen(tmp->next->name)) == 0)
		ft_swp(&tmp, &t_tmp, 0);
}

int	unset_first_value(char *key, t_list *tmp, t_list *t_tmp, int i)
{
	if (key && ft_strcmp(key, tmp->name) == 0)
	{
		ft_swp(&tmp, &t_tmp, 1);
		i++;
		return (i);
	}
	return (i);
}

void	ft_unset(char **key, t_list **export, int flag)
{
	int		i;
	t_list	*t_tmp;
	t_list	*tmp;

	i = 1;
	if (ft_len(key) == 1)
		return ;
	t_tmp = NULL;
	while (key[i])
	{
		tmp = *export;
		if (ft_check_unset_arg(key[i], flag) == 1
			|| ft_check_lst_name(key[i], export) == 1)
		{
			if (!key[i + 1])
				break ;
			i++;
		}
		i = unset_first_value(key[i], tmp, t_tmp, i);
		if (key[i] && ft_check_lst_name(key[i], export) == 0)
		{
			swap_unset_args(key[i], tmp, t_tmp);
			i++;
		}
	}
}
