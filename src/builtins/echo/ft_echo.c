/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 08:56:40 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/07 16:26:38 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	check_param_n(t_list **envcp, int i)
{
	t_list	*lst;
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
char	*search_varrr(t_list **envcp, int len_var, int start, int i)
{
	t_list	*lst;
	char	*var;
	char	*value;

	value = NULL;
	lst = *envcp;
	var = NULL;
	var = ft_substr(lst->cmd[i], start - 1, len_var);
	while (lst->next)
	{
		if (ft_strcmp(lst->name, var) == 0)
		{
			free(var);
			value = ft_strdup(lst->value);
			if (value)
				return (value);
		}
		lst = lst->next;
	}
	if (ft_strcmp(lst->name, var) == 0)
	{
		free(var);
		value = ft_strdup(lst->value);
		if (value)
			return (value);
	}
	free(var);
	return (NULL);
}

char	*ft_cpy(t_list *lst, int c, char *tmp)
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

void	print_doll(t_list *lst, int *i, int *j, int *c)
{
	if (lst->cmd[*i][*j] == '$' && (lst->cmd[*i][*j + 1] == ' '
		|| !lst->cmd[*i][*j + 1]))
	{
		lst->echo[*c] = '$';
		*c += 1;
		*j += 1;
	}
}

void	echo_exit_code(t_list *lst, int *i, int *j, int *c)
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
void	echo_var_env(t_list *lst, int *i, int *j, int *c)
{
	int		len_var;
	int		t;
	char	*tmp1;

	tmp1 = NULL;
	t = 0;
	len_var = 0;
	if (lst->flag == 1)
		return ;
	if (lst->cmd[*i][*j] == '$' && lst->cmd[*i][*j + 1] != '?')
	{
		*j += 1;
		while (lst->cmd[*i][*j] && ft_isalpha(lst->cmd[*i][*j]))
		{
			len_var++;
			*j += 1;
		}
		tmp1 = search_varrr(&lst, len_var, *j - len_var + 1, *i);
		len_var = 0;
		if (!tmp1)
			return ;
		while (tmp1[t])
		{
			lst->echo[*c] = tmp1[t++];
			*c += 1;
		}
	}
}

void	check_flag_for_quote(t_list *lst, int *i, int *j)
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
void	ft_cpy_and_print(t_list **envcp, int i)
{
	t_list	*lst;
	int		len_var;
	int		j;
	int		c;

	lst = *envcp;
	lst->echo = malloc(sizeof(char) * (lst->size + 1));
	if (!lst->echo)
		return ;
	len_var = 0;
	j = 0;
	c = 0;
	/*if (lst->flag != 1 && lst->flag != 2)
	{
		while (lst->cmd[i + 1])
		{
			printf("%s ", lst->cmd[i]);
			i++;
		}
	}*/
	while (lst->cmd[i] && ft_strcmp(lst->cmd[i], "|"))
	{
		j = 0;
		while (lst->cmd[i][j])
		{
			print_doll(lst, &i, &j, &c);
			echo_exit_code(lst, &i, &j, &c);
			echo_var_env(lst, &i, &j, &c);
			check_flag_for_quote(lst, &i, &j);
			if (lst->cmd[i][j])
			{
				lst->echo[c] = lst->cmd[i][j];
				c++;
				j++;
			}
		}
		if (lst->cmd[i + 1] && ft_strcmp(lst->cmd[i], "|"))
			lst->echo[c++] = ' ';
		i++;
	}
	lst->echo[c] = '\0';
}

void	ft_echo(t_list **envcp)
{
	t_list	*lst;
	int		i;
	int		flag;

	/* voir pour indexer i en parametre */
	i = 1;
	flag = 0;
	lst = *envcp;
	lst->len = 0;
	lst->size = 0;
	if (check_param_n(envcp, i) != 0)
	{
		if (lst->cmd[i + 1])
			i++;
		flag = 1;
	}
	else
		flag = 0;
	lst->size = ft_len_echo_arg(envcp, i);
//	printf("lst->size %d\n", lst->size);
	ft_cpy_and_print(envcp, i);
	printf("%s", lst->echo);
	if (flag == 0)
		printf("\n");
	g_exit_code = 0;
}
