/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:34:26 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/14 10:57:35 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	search_var2(t_data **envcp, int len_var, int start, int i)
{
	t_data	*lst;
	char	*var;

	lst = *envcp;
	var = NULL;
	var = ft_substr(lst->cmd[i], start - 1, len_var);
	while (lst->envcp->next)
	{
		if (ft_strcmp(lst->envcp->name, var) == 0)
		{
			free(var);
			return (ft_strlen(lst->envcp->value));
		}
		lst->envcp = lst->envcp->next;
	}
	if (ft_strcmp(lst->envcp->name, var) == 0)
	{
		free(var);
		return (ft_strlen(lst->envcp->value));
	}
	free(var);
	return (ft_strlen(lst->envcp->value));
}

int	doll(t_data **envcp, int j, int i)
{
	t_data	*lst;

	lst = *envcp;
	if (lst->cmd[i][j] == '$' && (lst->cmd[i][j + 1] == ' '
		|| !lst->cmd[i][j + 1]))
	{
		lst->size++;
		j++;
	}
	if (lst->cmd[i][j] == '$' && lst->cmd[i][j + 1] == '?')
	{
		lst->size += 2;
		j += 2;
	}
	return (j);
}

int	check_zero(t_data **envcp, int j, int i)
{
	t_data	*lst;

	lst = *envcp;
	if (lst->cmd[i][j] != '\0')
	{
		lst->size++;
		j++;
	}
	return (j);
}

void	count_len_var(t_data *lst, int *i, int *j, int *len_var)
{
	if (lst->cmd[*i][*j])
	{
		*j += 1;
		lst->size++;
	}
	while (lst->cmd[*i][*j] && ft_isalpha(lst->cmd[*i][*j]))
	{
		*len_var += 1;
		*j += 1;
	}
}

int	ft_len_echo_arg(t_data **envcp, int i)
{
	t_data	*lst;
	int		len_var;
	int		j;
	int		size;

	lst = *envcp;
	size = 0;
	j = 0;
	len_var = 0;
	while (lst->cmd[i])
	{
		j = 0;
		while (lst->cmd[i][j])
		{
			j = doll(envcp, j, i);
			if (lst->cmd[i][j] == '$' && lst->cmd[i][j + 1] != '?')
			{
				count_len_var(lst, &i, &j, &len_var);
				size += search_var2(envcp, len_var, j - len_var + 1, i);
				len_var = 0;
			}
			j = check_zero(envcp, j, i);
		}
		i++;
	}
	lst->size += size;
	return (lst->size);
}
