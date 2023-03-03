/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:32:15 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/03 12:42:31 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

/* print var example: $PWD */

void	ft_print_var(char **cmd, t_list **envcp)
{
	int		i;
	char	*var;

	i = 1;
	var = NULL;
	while (cmd[i])
	{
		if (ft_strncmp(cmd[i], "$", 1) == 0 && cmd[i + 1] != NULL)
		{
			var = ft_check_doll(cmd, envcp, i);
			if (var)
				printf("%s", var);
		}
		i++;
	}
	printf("\n");
}

/* len var environnement */

int	ft_len_var(char *line)
{
	int	i;

	i = 1;
	while (line[i] && line[i] != ' ')
		i++;
	return (i);
}

/* value for function ft_dquote */

int	ft_value_k(char **cmd)
{
	int	k;

	k = 1;
	if (ft_check_n(cmd[1]) == 0)
		k = 2;
	return (k);
}
