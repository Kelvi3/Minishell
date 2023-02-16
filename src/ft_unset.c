/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:28:11 by lulaens           #+#    #+#             */
/*   Updated: 2023/02/08 15:52:50 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"


// key = variable a supprimer
// key = lst->name
t_list	*ft_unset(t_list *envcp, char **key)
{
	int		i;
	t_list	*head;
	t_list	*tmp;

	i = 1;
	head = envcp;
	tmp = head;
	if (ft_len(key) == 1)
		return (NULL);
	while (ft_strncmp(key[i], head->next->name, ft_strlen(head->name)) != 0)
		head = head->next;
	printf("%s=%s\n", head->name, head->value);
	if (ft_strncmp(key[i], head->next->name, ft_strlen(head->name)) == 0)
	{
		free(head->next->name);
		free(head->next->value);
		//head = head->next;
		printf("%s=%s\n", head->next->name, head->next->value);
		while (head->next)
		{
			head->next->name = head->name;
			head->next->value = head->value;
			head = head->next;
		}
		head->next = NULL;
		//head->next = NULL;
		return (tmp);
	}
	return (NULL);
}
