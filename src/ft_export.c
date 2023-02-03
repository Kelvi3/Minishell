/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:18:25 by lulaens           #+#    #+#             */
/*   Updated: 2023/02/03 14:34:10 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// print copy env

static void	ft_print_envcp(t_list **envcp)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *envcp;
	while (tmp)
	{
		i = 0;
		printf("declare -x ");
		while (tmp->value[i])
		{
			printf("%c", tmp->value[i]);
			if (tmp->value[i] == '=')
				printf("\"");
			i++;
			if (tmp->value[i] == '\0')
				printf("\"\n");
		}
		tmp = tmp->next;
	}
	// voir free lst
}

// copy env in envcp

static void	ft_cpy_env(t_list **lst, char **env)
{
	int		i;
	t_list	*envcp;

	i = 0;
	while (env[i])
	{
		envcp = ft_lstnew(env[i]);
		ft_lstadd_back(lst, envcp);
		i++;
	}
}

// sort list ascii

void	ft_sort_ascii(t_list **lst)
{
	t_list	*tmp_i;
	t_list	*tmp_j;
//	t_list	*head;
	char	*temp;

	tmp_i = *lst;
//	head = tmp_i;
	while (tmp_i)
	{
		tmp_j = tmp_i->next;
		while (tmp_j)
		{
			if (ft_strncmp(tmp_i->value, tmp_j->value, 100) > 0)
			{
				temp = tmp_i->value;
				tmp_i->value = tmp_j->value;
				tmp_j->value = temp;
				tmp_i = *lst;
			}
			tmp_j = tmp_j->next;
		}
		tmp_i = tmp_i->next;
	}
}

/*void	ft_add_env(t_list **lst, char **args)
{
	int		i;
	t_list	*var;

	i = 1;
	while (args[i])
	{
		var = malloc(sizeof(t_list));
		var->value = ft_strdup(args[i]);
		var->next = NULL;
		i++;
	}
}*/

// export sans argument

void	ft_export(char **env, char **args)
{
	t_list		*envcp;
	(void) args;
	envcp = NULL;
	ft_cpy_env(&envcp, env);
//	if (nb_args > 1)
//		ft_add_env(&envcp, args);
	ft_sort_ascii(&envcp);
//	if (nb args == 1)
	ft_print_envcp(&envcp);
}
