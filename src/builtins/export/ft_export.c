/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:18:25 by lulaens           #+#    #+#             */
/*   Updated: 2023/02/16 10:49:18 by lulaens          ###   ########.fr       */
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

	new_var = malloc(sizeof(t_list));
	new_var->name = ft_strdup(name);
	if (value)
		new_var->value = ft_strdup(value);
	new_var->next = NULL;
	ft_lstadd_front(env_lst, new_var);
//	if (new_var)
//		free(new_var);
}

t_list	*ft_add_param_env(t_list *new_env, char **args)
{
	int		i;
	char	*name;
	char	*value;

	i = 1;
	while (args[i])
	{
		name = ft_cpy_name(args[i]);
		value = ft_cpy_value(args[i]);
		if (value)
			ft_add_lst(&new_env, name, value);
		else if (value == NULL)
			ft_add_lst(&new_env, name, value);
		free(name);
		free(value);
		i++;
	}
	return (new_env);
}

t_list	*init_lst(t_list *env_lst, char **env)
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
		ft_add_lst(&env_lst, name, value);
		i++;
		free(name);
		free(value);
	}
	return (env_lst);
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

void	ft_export(char **args, t_list **envcpp, t_list **export)
{
	t_list			*envcp;
	t_list			*copy;

	copy = *export;
	envcp = *envcpp;
	if (ft_check_name(args) == 1)
	{	
		ft_putstr_fd("bash: export: not a valid identifier\n", 2);
		return ;
	}
	if (ft_len(args) > 1)
	{
		if (ft_check_double(copy, envcp, args) == 0)
		{	
			*export = ft_add_param_env(copy, args);
			*envcpp = ft_add_param_env(envcp, args);
		}
	}
	ft_sort_ascii(copy);
	if (ft_len(args) == 1)
		ft_print_envcp(copy);
}