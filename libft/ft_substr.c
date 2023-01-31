/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:38:57 by lulaens           #+#    #+#             */
/*   Updated: 2022/10/13 14:10:17 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_while(size_t len, unsigned int start, char const *s, char *dst)
{
	size_t	i;

	i = 0;
	while (i < len && s[start])
	{
		dst[i] = s[start];
		i++;
		start++;
	}
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	if ((len > i && start > i) || start > i)
	{
		dst = ft_strdup(&s[i]);
		return (dst);
	}
	else if (len >= i)
	{
		dst = ft_strdup(&s[start]);
		return (dst);
	}
	dst = ft_calloc(sizeof(char), (len + 1));
	if (!dst)
		return (0);
	dst = ft_while(len, start, s, dst);
	return (dst);
}
