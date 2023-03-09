/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_env_execve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:40:48 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/08 13:12:21 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/* envoyer copy de env et pas export en paramtre */

static char	*cpy(char **envcpy, t_list *lst, int i)
{
	envcpy[i] = ft_strdup(lst->name);
	envcpy[i] = ft_strjoin(envcpy[i], "=");
	if (lst->value)
		envcpy[i] = ft_strjoin(envcpy[i], lst->value);
	return (envcpy[i]);
}

char	**cpy_env_execve(t_list	**envcp)
{
	t_list	*lst;
	char	**envcpy;
	int		i;

	lst = *envcp;
	i = 0;
	envcpy = NULL;
	if (envcpy)
		free_double_char(lst->envcpy);
	envcpy = malloc(sizeof(char *) * (ft_lstsize(lst) + 1));
	if (!envcpy)
		return (NULL);
	envcpy[i] = cpy(envcpy, lst, i);
	i++;
	lst = lst->next;
	while (lst)
	{
		envcpy[i] = cpy(envcpy, lst, i);
		i++;
		lst = lst->next;
	}
	envcpy[i] = NULL;
	return (envcpy);
}
