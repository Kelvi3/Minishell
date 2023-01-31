/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 09:44:12 by lulaens           #+#    #+#             */
/*   Updated: 2022/10/13 10:02:19 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_compt(const char *s, char c)
{
	unsigned int	i;
	unsigned int	compt;

	i = 0;
	compt = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			compt++;
		while (s[i] != c && s[i])
			i++;
	}
	return (compt);
}

static size_t	ft_condi(char const *s, char c, size_t len)
{
	if (!ft_strchr(s, c))
		len = ft_strlen(s);
	else
		len = ft_strchr(s, c) - s;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	size_t	len;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	dst = ft_calloc(sizeof(char *), (ft_compt(s, c) + 1));
	if (!dst)
		return (0);
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != '\0')
		{
			len = ft_condi(s, c, len);
			dst[i] = ft_substr(s, 0, len);
			s += len;
			i++;
		}
	}
	return (dst);
}
