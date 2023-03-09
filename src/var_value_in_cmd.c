/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_value_in_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:03:34 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/09 11:23:37 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	var_value(t_list **envcp)
{
	t_list	*lst;
	char	*tmp;
	char	*tmp1;
	int		len_var;
	size_t	len_cmd;
	int		flag;
	int		i;
	int		j;

	lst = *envcp;
	len_cmd = 0;
	len_var = 0;
	i = 0;
	j = 0;
	flag = 0;
	tmp = NULL;
	tmp1 = NULL;
	while (lst->cmd[i])
	{
		lst = *envcp;
		j = 0;
		while (lst->cmd[i][j])
		{
			if (lst->cmd[i][j] == '$' && lst->cmd[i][j + 1] != '?'
				&& lst->cmd[i][j + 1] && lst->flag != 1 && lst->flag != 2)
			{
				j++;
				while (lst->cmd[i][j] && ft_isalpha(lst->cmd[i][j]))
				{
					j++;
					len_var++;
				}
				len_cmd = ft_strlen(lst->cmd[i]) - len_var;
				tmp1 = ft_substr(lst->cmd[i], j, ft_strlen(lst->cmd[i]));
				if (flag == 0)
					tmp = search_varrr(&lst, len_var, j - len_var + 1, i);
				else
					tmp1 = search_varrr(&lst, len_var, j - len_var + 1, i);
				if (!tmp)
					break ; 
				len_var = 0;
				free(lst->cmd[i]);
				lst->cmd[i] = NULL;
				if(!lst->cmd[i])
					lst->cmd[i] = ft_strdup(tmp);
				if (flag == 1)
					lst->cmd[i] = ft_strjoin(lst->cmd[i], tmp1);
				else
					lst->cmd[i] = ft_strjoin(lst->cmd[i], tmp1);
				flag = 1;
			}
			j++;
		}
		i++;
	}

}
