/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 09:17:25 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/06 11:49:33 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"
/*
static void	print_error(int flag)
{
	if (flag == 0)
	{
		g_exit_code = 127;
		ft_putstr_fd(" command not found", 2);
	}
	if (flag == 1)
	{
		g_exit_code = 2;
		ft_putstr_fd("bash : syntax error near unexpected token `newline'\n", 2);
	}
	if (flag == 2)
		ft_putstr_fd("bash : syntax error near unexpected token `newline'\n", 2);
	if (flag == 3)
		ft_putstr_fd("bash : syntax error near unexpected token `>>'\n", 2);
}

static int	check_pipe_first(t_list **envcp, int i)
{
	t_list	*lst;

	lst = *envcp;
	if (lst->line[i] == '|')
	{
		i = pass_space(envcp, i);
		if (lst->line[i + 1] && lst->line[i] == '"')
		{
			if (lst->line[i + 1] == '|' && lst->line[i + 2] == '"'
				&& !lst->line[i + 3])
			{
				print_error(0);
				return (1);
			}
		}
		if (lst->line[i] == '|' && !lst->line[i + 1])
			return (1);
		if (lst->line[i] == '<')
		{
			i = pass_space(envcp, i);
			if (lst->line[i] == '|')
				return (1);
		}
	}
	return (i);
}

static int	pass_arg_echo(t_list **envcp, int i)
{
	t_list	*lst;

	lst = *envcp;
	while (lst->line[i] && (lst->line[i] == ' ' || lst->line[i] == '\''
			|| lst->line[i] == '"' || ft_isalpha(lst->line[i])))
		i++;
	while (lst->line[i] && lst->line[i] == ' ')
		i++;
	return (i);
}

static int	check_one_redirection(t_list **envcp, int i)
{
	t_list	*lst;

	lst = *envcp;
	if ((lst->line[i] == '<' || lst->line[i] == '>')
		&& !lst->line[i + 1])
	{
		print_error(1);
		return (1);
	}
	return (0);
}

int	ft_check_syntax(t_list **envcp, int i)
{
	t_list	*lst;

	lst = *envcp;
	i = pass_arg_echo(envcp, i);
	if (check_pipe_first(envcp, i) == 1)
		return (1);
	i = check_pipe_first(envcp, i);
	if (check_one_redirection(envcp, i) == 1)
		return (1);
	if (lst->line[i] == '|')
		i++;
	i = pass_space(envcp, i);
	if (lst->line[i] == '>' && !lst->line[i + 1])
	{
		print_error(2);
		return (1);
	}
	if (lst->line[i] == '>' && lst->line[i + 1] == '>' && !lst->line[i + 2])
	{
		print_error(3);
		return (1);
	}
	return (0);
}*/
