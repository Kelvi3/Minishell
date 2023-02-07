/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:18:25 by lulaens           #+#    #+#             */
/*   Updated: 2023/02/07 13:17:09 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <string.h>

// sort list ascii

void	ft_sort_ascii(t_list **lst)
{
	t_list	*tmp_i;
	t_list	*tmp_j;
	char	*temp_value;
	char	*temp_name;

	tmp_i = *lst;
	while (tmp_i)
	{
		tmp_j = tmp_i->next;
		while (tmp_j)
		{
			if (ft_strncmp(tmp_i->name, tmp_j->name,
					ft_strlen(tmp_j->name)) > 0)
			{
				temp_value = tmp_i->value;
				tmp_i->value = tmp_j->value;
				tmp_j->value = temp_value;
				temp_name = tmp_i->name;
				tmp_i->name = tmp_j->name;
				tmp_j->name = temp_name;
				tmp_i = *lst;
			}
			tmp_j = tmp_j->next;
		}
		tmp_i = tmp_i->next;
	}
}

void	ft_add_lst(t_list **env_lst, char *name, char *value)
{
	t_list	*new_var;

	if (value)
	{
		new_var = malloc(sizeof(t_list));
		new_var->name = ft_strdup(name);
		new_var->value = ft_strdup(value);
		new_var->next = *env_lst;
		*env_lst = new_var;
	}
	else
	{
		new_var = malloc(sizeof(t_list));
		new_var->name = ft_strdup(name);
		new_var->next = *env_lst;
		*env_lst = new_var;
	}
}
	/*	if (args[i][0] == '_' && tmp->name[0] == '_')
			{
				printf("name tmp == %s\n", tmp->name);
				printf("name arg == %s\n", args[i]);
				if (ft_strncmp(args[i], tmp->name, ft_strlen(args[i])) != 0)
				{
					printf("strncmp == %d\n", ft_strncmp(args[i], tmp->name, ft_strlen(args[i])));
					if (!ft_strchr(args[i], '='))
						return (1);
					//new_env = ft_add_param_env(new_env, args);
					return (5);
				}
			}*/

// if double replace value and return 1
char	*ft_name(char *args)
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	i = 0;
	tmp = NULL;
	while (args[i])
	{
		if (args[i] == '=')
			break ;
		i++;
	}
	tmp = malloc(sizeof(char) * (i + 1));
	while (j < i)
	{
		tmp[j] = args[j];
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}
int	ft_check_double(t_list *new_env, char **args)
{
	int		i;
	char	*name;
	t_list	*tmp;

	tmp = new_env;
	i = 1;
	while (tmp && args[i])
	{
		name = ft_name(args[i]);
		if (ft_strncmp(args[i], tmp->name, ft_strlen(name)) == 0)
		{
			if (!ft_strchr(args[i], '='))
				return (1);
			tmp->value = ft_strchr(args[i], '=') + 1;
			free(name);
			return (1);
		}
		free(name);
		tmp = tmp->next;
		if (tmp == NULL)
		{
			tmp = new_env;
			i++;
		}
	}
	return (0);
}

// check si le name est bon

int	ft_check_name(char **args)
{
	int	i;
	int	j;

	i = 1;
	while (args[i])
	{
		j = 0;
		if (ft_isalpha(args[i][0]) == 0 && args[i][0] != '_')
			return (1);
		while (args[i][j] && args[i][j] != '=')
		{
			if (ft_isalnum(args[i][j]) == 0 && args[i][j] != '_')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_list	*ft_add_param_env(t_list *new_env, char **args)
{
	int		i;
	char	*name;
	char	*value;

	i = 1;
	while (args[i])
	{
		value = ft_strchr(args[i], '=');
		name = args[i];
		if (value && ft_strncmp(name, value, ft_strlen(value)) != 0)
		{
			printf("1\n");
			*value = '\0';
			ft_add_lst(&new_env, name, value + 1);
		}
		else if (value == NULL)
		{
			printf("2\n");
			name = args[i];
			ft_add_lst(&new_env, name, value);
		}
		else
			ft_putstr_fd("errrrrror aplha\n", 2);
		i++;
	}
	return (new_env);
}

t_list	*init_lst(t_list *env_lst, char **env)
{
	char	*name;
	char	*value;
	int		i;

	i = 0;
	while (env[i])
	{
		value = ft_strchr(env[i], '=');
		if (value)
		{
			*value = '\0';
			name = env[i];
			ft_add_lst(&env_lst, name, value + 1);
		}
		i++;
	}
	return (env_lst);
}

void	ft_print_envcp(t_list **lst, char **env)
{
	int		i;
	t_list	*tmp;

	tmp = *lst;
	i = 0;
	(void) env;
	while (tmp)
	{
		if (tmp->name[0] == '_' && tmp->value)
			printf("declare x %s=\"%s\"\n", tmp->name, tmp->value);
		else if (tmp->value && tmp->name)
			printf("declare x %s=\"%s\"\n", tmp->name, tmp->value);
		else if (tmp->value == NULL && tmp->name[0] != '\0')
			printf("declare x %s\n", tmp->name);
		else
			printf("declare x %s=""\n", tmp->name);
		tmp = tmp->next;
		i++;
	}
}
// export sans argument
/*
int	ft_check_double_underscore(t_list *new_env, char **args)
{
	int		i;
	char	*value;
	char	*name;
	t_list	*tmp;

	i = 0;
	tmp = new_env;
	while (tmp && args[i])
	{
		value = ft_strchr(args[i], '=');
		if (args[i][0] == '_')
		{
			value = '\0';
			name = args[i];
			// ft_strlen(args[i]) est trop grand, prendre que le name
			if (ft_strncmp(args[i], tmp->name, ft_strlen(name)) == 0)
			{
				if (!ft_strchr(args[i], '='))
					return (1);
				tmp->value = value + 1;
				return (1);
			}
		}
	}
}*/

// probleme name avec underscore avec le checkdouble
// ne pas replace un export a=3 avec un export a

void	ft_export(char **env, char **args)
{
	static t_list		*envcp = NULL;

	if (envcp == NULL)
		envcp = init_lst(envcp, env);
	if (ft_check_name(args) == 1)
	{	
		printf("error\n");
		return ;  
	}
	if (ft_len(args) > 1)
	{
		// if no double, add env
		if (ft_check_double(envcp, args) == 0)
			envcp = ft_add_param_env(envcp, args);
	}
	ft_sort_ascii(&envcp);
	if (ft_len(args) == 1)
		ft_print_envcp(&envcp, env);
}
