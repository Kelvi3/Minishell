/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:37:48 by lulaens           #+#    #+#             */
/*   Updated: 2022/09/30 12:10:08 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	char	*tmp;

	tmp = (char *)src;
	i = 0;
	if (size == 0)
	{
		while (tmp[i])
			i++;
		return (i);
	}
	while (i < size - 1 && tmp[i] && size != 0)
	{
		dst[i] = tmp[i];
		i++;
	}
	dst[i] = '\0';
	i = 0;
	while (tmp[i])
		i++;
	return (i);
}
