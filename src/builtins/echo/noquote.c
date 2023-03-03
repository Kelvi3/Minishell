/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noquote.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:37:20 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/03 15:01:56 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	ft_delim_arg(t_list **envcp)
{
	t_list	*lst;
	int		i;

	i = 0;
	lst = *envcp;
	while (lst->cmd[i])
	{
		if (lst->cmd[i][0] == '>' || lst->cmd[i][0] == '<' || lst->cmd[i][0] == '|')
			return (i);
		i++;
	}
	return (i);
}

int	print_noquote(t_list **envcp, int i, int space)
{
	t_list	*lst;
	int		count;

	count = 1;
	lst = *envcp;
	while (lst->line[i] && count != ft_delim_arg(envcp))
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
		if (lst->line[i] == ' ')
		{
			while (lst->line[i] == ' ')
				i++;
			i--;
			count++;
		}
		if (lst->line[i] && lst->line[i] != '\'' && lst->line[i] != '"')
			printf("%c", lst->line[i]);
		i++;
	}
//	printf("count = %d\n", count);
//	printf("delim = %d\n", ft_delim_arg(envcp));
	return (i);
}
