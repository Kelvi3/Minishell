/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 08:56:40 by lulaens           #+#    #+#             */
/*   Updated: 2023/02/20 17:47:47 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"


/* si ya une redirection dans cote ou dcote ecrire la redirection */

void	ft_dquote(char **cmd, char *line, t_list **envcp, int i)
{
	int	k;

	k = ft_value_k(cmd);
	while (line[i])
	{
		if (line[i] == '$' && line[i + 1] != '?' && ft_isalpha(line[i + 1]))
		{
			printf("%s", ft_check_doll(cmd, envcp, k));
			if (k == 1)
				i += ft_len_var(line);
			else
				i += ft_len_var(line) + 1;
		}
		if (line[i] == '$' && line[i + 1] == '?')
		{
			printf("%d", g_exit_code);
			i += 2;
		}
		if (line[i] == ' ')
			k++;
		if (line[i] != '"')
			printf("%c", line[i]);
		i++;
	}
}

void	ft_squote(char *line, int i)
{
	while (line[i])
	{
		if (line[i] != '\'')
			printf("%c", line[i]);
		i++;
	}
}

void	ft_noquote(char *line, int i)
{
	while (line[i])
	{
		if (line[i] == '$' && line[i + 1] == '?')
		{
			printf("%d", g_exit_code);
			i += 2;
		}
		if (line[i] && line[i] != '\'' && line[i] != '"')
			printf("%c", line[i]);
		while (line[i] == ' ')
		{
			i++;
			if (line[i] != ' ')
			{
				i--;
				break ;
			}
		}
		i++;
	}
}

void	ft_check_quote(char *line, char **cmd, t_list **envcp, int i)
{
	if (ft_check_n(cmd[1]) == 0)
	{
		i = ft_pass_n(line, i);
		if (line[i] == '"')
			ft_dquote(cmd, line, envcp, i);
		else if (line[i] == '\'')
			ft_squote(line, i);
		else
			ft_noquote(line, i);
	}
	if (ft_check_n(cmd[1]) == 1)
	{
		while (line[i] && line[i] == ' ')
			i++;
		if (line[i] == '"')
			ft_dquote(cmd, line, envcp, i);
		else if (line[i] == '\'')
			ft_squote(line, i);
		else
			ft_noquote(line, i);
		printf("\n");
	}
}

void	ft_echo(char **cmd, t_list **envcp, char *line)
{
	int	i;

	i = check_cote_echo(line);
	if (i == 0)
	{
		ft_putstr_fd("error\n", 2);
		return ;
	}
	if (!line[i + 1])
	{
		printf("\n");
		return ;
	}
	ft_check_quote(line, cmd, envcp, i);
	return ;
}
