/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:18:25 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/14 11:09:10 by lulaens          ###   ########.fr       */
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
		new_var = malloc(sizeof(t_data));
		new_var->name = ft_strdup(name);
		new_var->value = ft_strdup(value);
		new_var->next = NULL;
		ft_lstaddfront(env_lst, new_var);
	}
	if (!value)
	{
		new_var = malloc(sizeof(t_data));
		new_var->name = ft_strdup(name);
		new_var->value = NULL;
		new_var->next = NULL;
		ft_lstaddfront(env_lst, new_var);
	}
}

t_list	*ft_add_param_env(t_list *new_env, char **args, char *line, int i)
{
	char	*name;
	char	*value;

	while (args[i] && args[i][0] != '|')
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
//		if (name)
//			free(name);
		i++;
//		if (value)
//			free(value);
		value = NULL;
		name = NULL;
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

int	check_pipex(char **cmd)
{
	int		i;

	i = 1;
	while (cmd[i])
	{
		if (ft_strcmp(cmd[i], "|") == 0)
			return (1);
		i++;
	}
	return (0);
}

int	check_after_export(char **cmd)
{
	int	i;

	i = 1;
	if (ft_strcmp(cmd[i], "|") == 0)
		return (1);
	return (0);
}

void	ft_export(t_data **data)
{
	t_data	*tmp;
	int		i;

	i = 1;
	tmp = *data;
	if (check_pipex(tmp->cmd) == 1 && check_after_export(tmp->cmd) == 0)
	{
		g_exit_code = 1;
		return ;
	}
	if (check_pipex(tmp->cmd) == 1 && check_after_export(tmp->cmd) == 1)
	{
		ft_sort_ascii(tmp->export);
		if (ft_len(tmp->cmd) == 1)
			ft_print_envcp(tmp->export);
	}
	if (ft_quote_value(tmp->line) == 0)
	{
		if (ft_check_name(tmp->cmd) == 1)
		{
			g_exit_code = 1;
			return ;
		}
	}
	if (ft_len(tmp->cmd) > 1)
	{
		g_exit_code = 0;
		if (ft_check_double(tmp->envcp, tmp->cmd) == 0)
			tmp->export = ft_add_param_env(tmp->export, tmp->cmd, tmp->line, i);
		if (ft_check_double(tmp->envcp, tmp->cmd) == 0)
			tmp->envcp = ft_add_param_env(tmp->envcp, tmp->cmd, tmp->line, i);
	}
	//(*data)->envcpy = cpy_env_execve(*data);
	ft_sort_ascii(tmp->export);
	if (ft_len(tmp->cmd) == 1)
		ft_print_envcp(tmp->export);
}
