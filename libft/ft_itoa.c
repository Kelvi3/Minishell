/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:16:22 by lulaens           #+#    #+#             */
/*   Updated: 2022/10/10 16:00:09 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_compt(long nb)
{
	long	size;

	size = 0;
	if (nb < 0)
		size++;
	else if (nb == 0)
		size++;
	while (nb != 0)
	{
		size++;
		nb /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		size;
	long	nb;
	char	*s;

	nb = n;
	size = ft_compt(nb);
	s = malloc(sizeof(char) * (size + 1));
	if (!s)
		return (NULL);
	if (nb < 0)
	{
		s[0] = '-';
		nb *= -1;
	}
	else if (nb == 0)
		s[0] = '0';
	s[size] = '\0';
	while (nb > 0)
	{
		s[size - 1] = (nb % 10) + 48;
		nb /= 10;
		size--;
	}
	return (s);
}
