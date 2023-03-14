/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 08:56:40 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/14 11:09:37 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	check_param_n(t_data **envcp, int i)
{
	t_data	*lst;
	int		j;

	j = 0;
	lst = *envcp;
	if (lst->cmd[i][j] == '-')
	{
		j++;
		while (lst->cmd[i][j])
		{
			if (lst->cmd[i][j] != 'n')
				return (0);
			j++;
		}
	}
	else
		return (0);
	return (i);
}

char	*ft_cpy(t_data *lst, int c, char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		lst->echo[c] = tmp[i];
		c++;
		i++;
	}
	return (lst->echo);
}

void	check_flag_for_quote(t_data *lst, int *i, int *j)
{
	while (lst->cmd[*i][*j] == '"' && lst->flag != 1)
		*j += 1;
	while (lst->cmd[*i][*j] == '\'' && lst->flag == 0)
		*j += 1;
	if (lst->flag == 1)
	{
		while (lst->cmd[*i][*j] && lst->cmd[*i][*j] == '\'')
			*j += 1;
	}
}

void	ft_echo(t_data **envcp)
{
	t_data	*lst;
	int		i;
	int		flag;

	i = 1;
	flag = 0;
	lst = *envcp;
	lst->len = 0;
	lst->size = 0;
	if (!lst->cmd[i])
	{
		printf("\n");
		return ;
	}
	if (check_param_n(envcp, i) != 0)
	{
		if (lst->cmd[i + 1])
			i++;
		flag = 1;
	}
	else
		flag = 0;
	if (flag == 1)
		if (!lst->cmd[i + 1])
			return ;
	lst->size = ft_len_echo_arg(envcp, i);
	ft_cpy_cmd(envcp, i);
	printf("%s", lst->echo);
	if (flag == 0)
		printf("\n");
	free(lst->echo);
	g_exit_code = 0;
}
