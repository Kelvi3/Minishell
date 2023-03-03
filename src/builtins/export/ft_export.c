/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:18:25 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/03 15:10:04 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

// sort list ascii

void	ft_sort_ascii(t_list *lst)
{
	t_list	*tmp_i;
	t_list	*tmp_j;

	tmp_i = lst;
	while (tmp_i)
	{
		if (tmp_i->next)
			tmp_j = tmp_i->next;
		while (tmp_j)
		{
			if (ft_strncmp(tmp_i->name, tmp_j->name,
					ft_strlen(tmp_j->name)) > 0)
			{
				ft_swap_lst(&tmp_i, &tmp_j);
				tmp_i = lst;
			}
			tmp_j = tmp_j->next;
		}
		tmp_i = tmp_i->next;
	}
}
/* voir pour changer avec lstaddback et lstnew */
void	ft_add_lst(t_list **env_lst, char *name, char *value)
{
	t_list	*new_var;

	new_var = NULL;
	if (value)
	{
		new_var = malloc(sizeof(t_list));
		new_var->name = ft_strdup(name);
		new_var->value = ft_strdup(value);
		new_var->next = NULL;
		ft_lstadd_front(env_lst, new_var);
	}
	if (!value)
	{
		new_var = malloc(sizeof(t_list));
		new_var->name = ft_strdup(name);
		new_var->value = NULL;
		new_var->next = NULL;
		ft_lstadd_front(env_lst, new_var);
	}
}

t_list	*ft_add_param_env(t_list *new_env, char **args, char *line)
{
	int		i;
	char	*name;
	char	*value;

	i = 1;
	while (args[i] && (args[i][0] != '|' || args[i][0] != '<'
			|| args[i][0] != '>'))
	{
		name = ft_cpy_name(args[i]);
		if (ft_quote_value(line) == 1)
			value = test_export(line);
		if (ft_quote_value(line) == 1)
			i++;
		else
			value = ft_cpy_value(args[i]);
		if (value)
			ft_add_lst(&new_env, name, value);
		else if (value == NULL)
			ft_add_lst(&new_env, name, value);
		free(name);
		if (value)
			free(value);
		i++;
	}
	return (new_env);
}

void	init_env(t_list **env_lst, char **env)
{
	int		i;
	int		j;
	char	*value;
	char	*name;

	i = 0;
	j = 0;
	name = NULL;
	value = NULL;
	while (env[i])
	{
		name = ft_cpy_name(env[i]);
		value = ft_cpy_value(env[i]);
		ft_add_lst(env_lst, name, value);
		i++;
		free(name);
		if (value)
			free(value);
	}
}

t_list	*ft_copy_lst(t_list *copy, t_list *envcp)
{
	t_list	*tmp;

	tmp = envcp;
	while (tmp)
	{
		ft_add_lst(&copy, tmp->name, tmp->value);
		tmp = tmp->next;
	}
	return (copy);
}

/* probleme parsing (export HELLO="123 A-") */
/* arg[1] = HELLO=123  arg[2] = A- */

void	ft_export(t_list **envcpp, t_list **export)
{
	t_list			*envcp;
	t_list			*copy;

	copy = *export;
	envcp = *envcpp;
	if (ft_quote_value(envcp->line) == 0)
	{
		if (ft_check_name(envcp->cmd) == 1)
		{
			g_exit_code = 1;
			return ;
		}
	}
	if (ft_len(envcp->cmd) > 1)
	{
		g_exit_code = 0;
		if (ft_check_double(copy, envcp->cmd) == 0)
			*export = ft_add_param_env(copy, envcp->cmd, envcp->line);
		if (ft_check_double(envcp, envcp->cmd) == 0)
			*envcpp = ft_add_param_env(envcp, envcp->cmd, envcp->line);
	}
	ft_sort_ascii(copy);
	if (ft_len(envcp->cmd) == 1)
		ft_print_envcp(copy);
}
