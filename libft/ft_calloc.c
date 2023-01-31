/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:01:19 by lulaens           #+#    #+#             */
/*   Updated: 2022/10/22 13:40:04 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;

	if (nmemb == 0 || size == 0)
	{
		str = malloc(0);
		if (!str)
			return (NULL);
		return (str);
	}
	if (nmemb * size / size != nmemb)
		return (0);
	str = malloc(size * nmemb);
	if (!str)
		return (0);
	ft_bzero(str, nmemb * size);
	return (str);
}
