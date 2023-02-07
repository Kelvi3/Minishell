/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:08:10 by lulaens           #+#    #+#             */
/*   Updated: 2023/02/07 13:41:13 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_env(char **env, char **cmd)
{
	int	i;

	(void) cmd;
	i = 0;
	printf("lebnnnnnnnnnnnnnnnnnnnn %d\n", ft_len(cmd));
	if (ft_len(cmd) > 1)
		ft_putstr_fd("env : error too many arguments", 2);
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
}
