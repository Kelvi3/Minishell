/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:41:22 by tcazenav          #+#    #+#             */
/*   Updated: 2023/03/08 11:37:09 by tcazenav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	check_file(char *file)
{
	if (access(file, F_OK) == -1)
	{
		ft_put_error(": No such file or directory\n", file);
		return (1);
	}
	if (access(file, R_OK) == -1)
	{
		ft_put_error(": Permission denied\n", file);
		return (1);
	}
	return (0);
}

void	multi_pipe(char **cmd, char **env, int nb_pipe)
{
	int		i;
	t_pipe	args;

	i = 0;
	args.infile = -1;
	args.outfile = -1;
	args.nb_pipe = nb_pipe;
	if (if_in_no_out(cmd) > 0 && check_file(cmd[found_infile(cmd)]) == 0)
		args.infile = open(cmd[found_infile(cmd)], O_RDONLY);
	if (i - 2 >= 0 && cmd[i - 2][0] == '>' && check_file(cmd[i - 1]) == 0)
		args.outfile = open(cmd[i - 1], O_RDWR | O_CREAT | O_TRUNC, 0664);
	if (if_in_no_out(cmd) == -1)
		return ;
	else
		exec_multi_cmd(env, cmd, args);
	i = 0;
	while (i <= args.nb_pipe)
	{
		waitpid(-1, NULL, 0);
		i++;
	}
}

void	no_pipe(char **cmd, char **env)
{
	int		i;
	int		redirection;
	t_pipe	args;

	i = 0;
	redirection = 0;
	args.infile = -1;
	args.outfile = -1;
	while (cmd[i])
	{
		if (cmd[i][0] == '<' || cmd[i][0] == '>')
			redirection = 1;
		i++;
	}
	if (redirection == 0)
		exec_simple_cmd(env, cmd);
	if (redirection == 0)
		return ;
	if (if_in_no_out(cmd) == -1)
		return ;
	if (if_in_no_out(cmd) > 0 && check_file(cmd[found_infile(cmd)]) == 0)
		args.infile = open(cmd[found_infile(cmd)], O_RDONLY);
	if (i - 2 >= 0 && cmd[i - 2][0] == '>' && check_file(cmd[i - 1]) == 0)
		args.outfile = open(cmd[i - 1], O_RDWR | O_CREAT | O_TRUNC, 0664);
	if (if_in_a_out(cmd) > 1 && args.infile > 0 && args.outfile > 0)
		exec_no_pipe_outfile_infile(args, env, cmd);
	else if (if_in_no_out(cmd) > 0 && args.infile >= 0)
		exec_no_pipe_infile(args, env, cmd);
	else if (if_in_no_out(cmd) == 0 && args.outfile >= 0)
		exec_no_pipe_outfile(args, env, cmd);
	else
		g_exit_code = 1;
}

/* compt nb pipe and condition if multi_pipe or no_pipe */

void	parse_pipe(char **cmd, char **env)
{
	int	i;
	int	nb_pipe;

	i = 0;
	nb_pipe = 0;
	while (cmd[i])
	{	
		if (cmd[i][0] == '|')
			nb_pipe++;
		i++;
	}
	if (nb_pipe > 0)
		multi_pipe(cmd, env, nb_pipe);
	else if (nb_pipe == 0)
		no_pipe(cmd, env);
}

int	is_pipe(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[0][0] == '>'
			|| ft_strncmp(cmd[0], ">>", 2) == 0
			|| (cmd[i][0] == '<' && cmd[1] == NULL))
		{
			ft_err_syntax(cmd);
			g_exit_code = 2;
			return (0);
		}
		i++;
	}
	if (ft_strncmp(cmd[0], "echo", 4) != 0
		&& ft_strncmp(cmd[0], "exit", 4) != 0
		&& ft_strncmp(cmd[0], "env", 3) != 0
		&& ft_strncmp(cmd[0], "unset", 5) != 0
		&& ft_strncmp(cmd[0], "export", 6) != 0
		&& ft_strncmp(cmd[0], "pwd", 3) != 0
		&& ft_strncmp(cmd[0], "cd", 2) != 0)
		return (1);
	return (0);
}
