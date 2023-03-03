/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:02:44 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/01 17:45:53 by tcazenav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	free_double_char(char **arg)
{
	int	i;

	i = 0;
	while (arg && arg[i])
	{
		free(arg[i]);
		arg[i] = NULL;
		i++;
	}
	free(arg);
	arg = NULL;
}

void	free_lst(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp1;

	tmp1 = NULL;
	tmp = *lst;
	while (tmp)
	{
		free(tmp->name);
		if (tmp->value)
			free(tmp->value);
		tmp1 = tmp->next;
		free(tmp);
		tmp = tmp1;
	}
}

void	free_double_int(int **arg, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(arg[i]);
		i++;
	}
	free(arg);
}
