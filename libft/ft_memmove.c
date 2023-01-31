/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:34:33 by lulaens           #+#    #+#             */
/*   Updated: 2022/10/10 16:17:21 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*sc;

	sc = (unsigned char *)src;
	dst = (unsigned char *)dest;
	if (!sc && !dst)
		return (NULL);
	if (dst > sc)
	{
		while (n > 0)
		{
			n--;
			dst[n] = sc[n];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return ((void *)dst);
}
