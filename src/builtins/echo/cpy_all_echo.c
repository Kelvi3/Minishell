/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_all_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:43:12 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/10 14:49:14 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	cpy_char(t_data *lst, int *i, int *j, int *c)
{
	if (lst->cmd[*i][*j])
	{
		lst->echo[*c] = lst->cmd[*i][*j];
		*c += 1;
		*j += 1;
	}
}

void	cpy_simple_doll(t_data *lst, int *i, int *j, int *c)
{
	if (lst->cmd[*i][*j] == '$' && (lst->cmd[*i][*j + 1] == ' '
		|| !lst->cmd[*i][*j + 1]))
	{
		lst->echo[*c] = '$';
		*c += 1;
		*j += 1;
	}
}

void	cpy_exit_code(t_data *lst, int *i, int *j, int *c)
{
	char	*tmp;
	int		t;

	t = 0;
	tmp = NULL;
	if (lst->flag == 1)
		return ;
	if (lst->cmd[*i][*j] == '$' && lst->cmd[*i][*j + 1] == '?')
	{
		tmp = ft_itoa(g_exit_code);
		if (tmp)
		{
			while (tmp[t])
			{
				lst->echo[*c] = tmp[t];
				*c += 1;
				t++;
			}
		}
		*j += 2;
		if (tmp)
			free(tmp);
		tmp = NULL;
	}
}

void	cpy_all(t_data *lst, int *i, int *j, int *c)
{
	cpy_simple_doll(lst, i, j, c);
	cpy_exit_code(lst, i, j, c);
	cpy_var_env(lst, i, j, c);
	check_flag_for_quote(lst, i, j);
	cpy_char(lst, i, j, c);
}

void	ft_cpy_cmd(t_data **data, int i)
{
	t_data	*lst;
	int		len_var;
	int		j;
	int		c;

	lst = *data;
	lst->echo = calloc(sizeof(char), (lst->size + 1));
	if (!lst->echo)
		return ;
	len_var = 0;
	j = 0;
	c = 0;
	while (lst->cmd[i] && ft_strncmp(lst->cmd[i], "|", 1)
		&& ft_strcmp(lst->cmd[i], "<") && ft_strcmp(lst->cmd[i], ">")
		&& ft_strcmp(lst->cmd[i], "<<") && ft_strcmp(lst->cmd[i], ">>"))
	{
		j = 0;
		while (lst->cmd[i][j])
			cpy_all(lst, &i, &j, &c);
		if (lst->cmd[i + 1] && ft_strcmp(lst->cmd[i], "|"))
			lst->echo[c++] = ' ';
		i++;
	}
	lst->echo[c] = '\0';
}
