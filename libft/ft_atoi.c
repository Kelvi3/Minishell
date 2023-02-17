/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:17:49 by lulaens           #+#    #+#             */
/*   Updated: 2023/02/16 16:09:29 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(const char *str, int i)
{
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

long long	ft_atoi(const char *nptr)
{
	int				i;
	int				sign;
	long long		res;

	i = 0;
	sign = 1;
	res = 0;
	i = ft_isspace(nptr, i);
	if (nptr[i] == 45)
		sign = -1;
	if (nptr[i] == 45)
		i++;
	else if (nptr[i] == 43)
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (res * sign > 9223372036854775807
			|| res * sign <= (-9223372036854775807 - 1))
			return (1);
		res *= 10;
		res += (nptr[i] - 48);
		i++;
	}
	return (sign * res);
}
