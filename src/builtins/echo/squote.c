/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   squote.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:04:30 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/03 12:08:21 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static int	count_nb_squote(t_list **envcp, int i)
{
	int		count;
	t_list	*lst;

	count = 0;
	lst = *envcp;
	while (lst->line[i])
	{
		if (lst->line[i] == '\'')
			count++;
		i++;
	}
	return (count);
}

void	print_squote(t_list **envcp, int i)
{
	t_list	*lst;
	int		count;

	count = 0;
	lst = *envcp;
	while (lst->line[i] && count != count_nb_squote(envcp, i))
	{
		if (lst->line[i] != '\'')
			printf("%c", lst->line[i]);
		i++;
	}
}
