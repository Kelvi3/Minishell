/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:08:10 by lulaens           #+#    #+#             */
/*   Updated: 2023/02/09 14:42:49 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_env(t_list *envcp, char **cmd)
{
	t_list	*tmp;

	tmp = envcp;
	if (ft_len(cmd) > 1)
	{
		ft_putstr_fd("env : error too many arguments\n", 2);
		return ;
	}
	while (tmp)
	{
		printf("%s=%s\n", tmp->name, tmp->value);
		tmp = tmp->next;
	}
}
