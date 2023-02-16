/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:38:26 by lulaens           #+#    #+#             */
/*   Updated: 2023/02/16 10:26:17 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_print_envcp(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->value && tmp->name && tmp->name[0] != '_')
			printf("declare -x %s=\"%s\"\n", tmp->name, tmp->value);
		else if (tmp->name && !tmp->value)
			printf("declare -x %s\n", tmp->name);
		else if (tmp->name && tmp->value[0] == '\0')
			printf("declare -x %s=""\n", tmp->name);
		tmp = tmp->next;
	}
}

void	ft_swap_lst(t_list **tmp_i, t_list **tmp_j)
{
	char	*temp_value;
	char	*temp_name;

	temp_value = (*tmp_i)->value;
	(*tmp_i)->value = (*tmp_j)->value;
	(*tmp_j)->value = temp_value;
	temp_name = (*tmp_i)->name;
	(*tmp_i)->name = (*tmp_j)->name;
	(*tmp_j)->name = temp_name;
}

char	*ft_cpy_name(char *args)
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
	if (!tmp)
		return (NULL);
	while (j < i)
	{
		tmp[j] = args[j];
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}

char	*ft_cpy_value(char *args)
{
	int		j;
	int		len;
	char	*value;

	j = 0;
	len = ft_strlen(args);
	value = NULL;
	while (j < len)
	{
		if (args[j] == '=')
		{
			value = malloc(sizeof(char) * (len - j) + 1);
			if (!value)
				return (NULL);
			ft_strlcpy(value, args + j + 1, len - j);
			return (value);
		}
		j++;
	}
	return (NULL);
}
