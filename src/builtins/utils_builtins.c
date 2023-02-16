/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 09:38:58 by lulaens           #+#    #+#             */
/*   Updated: 2023/02/09 14:43:19 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_check_alpha_export(char *args)
{
	int	i;

	i = 0;
	while (args[i] != '=')
	{
		if (!(args[i] >= 'A' && args[i] <= 'Z')
			|| !(args[i] >= 'a' && args[i] <= 'z'))
			return (1);
		i++;
	}
	return (0);
}
