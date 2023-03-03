/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noquote.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:37:20 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/03 12:37:57 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	print_noquote(t_list **envcp, int i, int space)
{
	t_list	*lst;

	lst = *envcp;
	while (lst->line[i] && lst->line[i] != '|'
		&& lst->line[i] != '<' && lst->line[i] != '>')
	{
		if (lst->line[i] == '$' && lst->line[i + 1] == '?')
		{
			printf("%d", g_exit_code);
			i += 2;
		}
		if (lst->line[i] == '$' && lst->line[i + 1])
		{
			printf("%s", ft_check_doll(lst->cmd, envcp, space));
			if (space == 1)
				i += ft_len_var(lst->line);
			else
				i += ft_len_var(lst->line) + 1;
		}
		if (lst->line[i] && lst->line[i] != '\'' && lst->line[i] != '"')
			printf("%c", lst->line[i]);
		i++;
	}
}
