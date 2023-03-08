/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:27:04 by tcazenav          #+#    #+#             */
/*   Updated: 2023/03/03 15:55:52 by tcazenav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_put_error(char *str, char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		write(2, &cmd[i], 1);
		i++;
	}
	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

void	ft_err_syntax(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i] && ft_strncmp(cmd[0], ">>>", 3) != 0)
	{
		if (cmd[0][0] == '>' || (cmd[i][0] == '<' && cmd[i + 1] == NULL))
			ft_put_error("`newline'", " syntax error near unexpected token ");
		if (i - 1 >= 0)
		{
			if ((ft_strncmp(cmd[i], "|", 1) == 0 && cmd[i - 1][0] == '<')
				|| (ft_strncmp(cmd[i], "|", 1) == 0 && cmd[i - 1][0] == '>')
				|| (ft_strncmp(cmd[i], "|", 1) == 0 && cmd[i - 1][0] == '|'))
			{
				write(2, " syntax error near unexpected token `|'", 39);
				return ;
			}
		}
		i++;
	}
	if (ft_strncmp(cmd[0], ">>>", 3) == 0 && cmd[1] == NULL)
		write(2, " syntax error near unexpected token `>'", 39);
	if (ft_strncmp(cmd[0], "|", 1) == 0)
		write(2, " syntax error near unexpected token `|'", 39);
	write(2, "\n", 1);
}
