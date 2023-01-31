/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:12:33 by lulaens           #+#    #+#             */
/*   Updated: 2022/10/13 14:12:44 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_comp(char c, const char *set)
{
	unsigned int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	d;
	size_t	end;
	char	*dst;

	if (!s1)
		return (NULL);
	if (*s1 == '\0')
	{
		dst = ft_strdup("");
		return (dst);
	}
	if (*set == '\0')
	{
		dst = ft_strdup(s1);
		return (dst);
	}
	d = 0;
	end = ft_strlen(s1);
	while (ft_comp(s1[d], set) == 0)
		d++;
	while (ft_comp(s1[end - 1], set) == 0)
		end--;
	dst = ft_substr(s1, d, (end - d));
	return (dst);
}
