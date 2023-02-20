/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:14:45 by lulaens           #+#    #+#             */
/*   Updated: 2023/02/18 15:26:50 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void	*content)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	tmp->value = content;
	tmp->next = NULL;
	return (tmp);
}
