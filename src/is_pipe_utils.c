/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pipe_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:02:38 by tcazenav          #+#    #+#             */
/*   Updated: 2023/03/10 13:02:59 by tcazenav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	if_in_no_out(char **cmd)
{
	int	i;
	int	redirect;

	redirect = 0;
	i = 0;
	while (cmd[i] != NULL)
	{
		if (cmd[i][0] == '<' && cmd[i][1] == '\0')
			redirect++;
		if (cmd[i][0] == '<' && cmd[i][1] != '\0')
		{
			if (check_file(cmd[i]) == 1)
			{	
				g_exit_code = 2;
				return (-1);
			}
		}
		i++;
	}
	return (redirect);
}

int	if_in_a_out(char **cmd)
{
	int	i;
	int	redirect;

	redirect = 0;
	i = 0;
	while (cmd[i] != NULL)
	{
		if ((cmd[i][0] == '<' && cmd[i][1] == '\0')
			|| (cmd[i][0] == '>' && cmd[i][1] == '\0'))
			redirect++;
		i++;
	}
	return (redirect);
}

int	found_infile(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i] != NULL)
		i++;
	i--;
	while (i >= 0)
	{
		if (cmd[i][0] == '<')
		{
			if (access(cmd[i + 2], F_OK) == 0)
				return (i + 2);
			return (i + 1);
		}
		i--;
	}
	return (0);
}

int	is_builtins(char *cmd)
{
	if (ft_strncmp(cmd, "echo", 4) != 0
		&& ft_strncmp(cmd, "exit", 4) != 0
		&& ft_strncmp(cmd, "env", 3) != 0
		&& ft_strncmp(cmd, "unset", 5) != 0
		&& ft_strncmp(cmd, "export", 6) != 0
		&& ft_strncmp(cmd, "pwd", 3) != 0
		&& ft_strncmp(cmd, "cd", 2) != 0)
		return (1);
	return (0);
}

void	make_builtins(t_pipe args, int i)
{
	printf("MAKE BUILTINS\n");
	if (ft_strncmp(args.arg[0], "echo", 4) == 0)
		ft_echo(&args.exec, i);
	if (ft_strncmp(args.arg[0], "exit", 4) == 0)
		ft_exit(args.arg, &args.exec, &args.exec);
	if (ft_strncmp(args.arg[0], "env", 3) == 0)
		ft_env(&args.exec, i);
	//if (ft_strncmp(args.arg[0], "unset", 5) == 0)
	if (ft_strncmp(args.arg[0], "export", 6) == 0)
		ft_export(&args.exec, &args.exec, i);
	if (ft_strncmp(args.arg[0], "pwd", 3) == 0)
		ft_pwd();
	if (ft_strncmp(args.arg[0], "cd", 2) == 0)
		ft_cd(&args.exec);
}
