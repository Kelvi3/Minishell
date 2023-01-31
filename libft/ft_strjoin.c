/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:33:03 by lulaens           #+#    #+#             */
/*   Updated: 2022/10/22 13:27:26 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(char const *s1, char const *s2)
{
	size_t	len_1;
	size_t	len_2;
	size_t	big_len;

	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	big_len = len_1 + len_2;
	return (big_len);
}

static char	*ft_strcat(const char *s1, const char *s2, char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	size = ft_size(s1, s2);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str = ft_strcat(s1, s2, str);
	return (str);
}
