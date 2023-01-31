/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:20:09 by lulaens           #+#    #+#             */
/*   Updated: 2022/10/22 13:28:52 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_d;
	size_t	len_s;
	size_t	big_len;
	size_t	len_sls;
	size_t	j;

	if (((dst == NULL) || (src == NULL)) && size == 0)
		return (0);
	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	len_sls = size + len_s;
	if (size == 0 || len_d > size)
		return (len_sls);
	j = 0;
	while (src[j] && (len_d + j < size - 1))
	{
		dst[len_d + j] = src[j];
		j++;
	}
	dst[len_d + j] = '\0';
	big_len = len_d + len_s;
	return (big_len);
}
