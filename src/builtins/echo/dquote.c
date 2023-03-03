/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dquote.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:47:00 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/03 12:28:41 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"
#include <ctype.h>

static void	print_exit_code(int *i)
{
	printf("%d", g_exit_code);
	*i += 2;
}

static int	count_nb_dquote(t_list **envcp, int i)
{
	int		count;
	t_list	*lst;

	lst = *envcp;
	count = 0;
	while (lst->line[i])
	{
		if (lst->line[i] == '"')
			count++;
		i++;
	}
	return (count);
}


int	count_nb_space(t_list **envcp, int i)
{
	int		count;
	t_list	*lst;

	lst = *envcp;
	count = 0;
	while (lst->line[i] && lst->line[i] != '$')
	{
		if (lst->line[i] == ' ')
			count++;
		i++;
	}
	return (count);
}

void	print_dquote(t_list **envcp, int i, int count, int space)
{
	t_list	*lst;
	int	k;

	lst = *envcp;
	i = pass_dquote_squote(envcp, i);
	k = ft_value_k(lst->cmd);
	(void)space;
	while (lst->line[i] && count != count_nb_dquote(envcp, i))
	{
		/* var d'env ex : $PWD */
		if (lst->line[i] == '$' && lst->line[i + 1] != '?'
			&& ft_isalpha(lst->line[i + 1]))
		{
			printf("%s", ft_check_doll(lst->cmd, envcp, k));
			if (space == 1)
				i += ft_len_var(lst->line);
			else
				i += ft_len_var(lst->line) + 1;
		}
		/* exit code */
		if (lst->line[i] == '$' && lst->line[i + 1] == '?')
			print_exit_code(&i);
		/* print le reste */
		if (lst->line[i] == ' ')
			k++;
		if (lst->line[i] != '"')
			printf("%c", lst->line[i]);
		i++;
	}
}
