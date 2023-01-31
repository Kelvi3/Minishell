/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 09:40:26 by lulaens           #+#    #+#             */
/*   Updated: 2022/10/13 15:58:15 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	len_l;
	char	*big_i;

	i = 0;
	len_l = ft_strlen(little);
	if (len == 0 && *little == '\0')
		return ((char *)big);
	if (*little == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (i <= len - len_l && big[i])
	{
		if (ft_strncmp(&big[i], &little[0], len_l) == 0)
		{	
			big_i = (char *)big + i;
			return (big_i);
		}
		i++;
	}
	return (NULL);
}
