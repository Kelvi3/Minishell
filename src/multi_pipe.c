/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:35:42 by tcazenav          #+#    #+#             */
/*   Updated: 2023/03/14 05:53:35 by tcazenav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	next_path(char **cmd, int index)
{
	if (cmd[index][0] == '|')
		return (index + 1);
	if (index == 0)
		return (index);
	while (cmd[index][0] != '|' && cmd[index] != NULL)
		index++;
	return (index + 1);
}

void	close_pipe(t_pipe args, int **pipefd)
{
	int	i;

	i = 0;
	while (args.nb_pipe > i)
	{
		close(pipefd[i][0]);
		close(pipefd[i][1]);
		i++;
	}
}

int	**init_pipe(t_pipe args)
{
	int	i;

	args.pipefd = malloc(sizeof(int *) * args.nb_pipe);
	if (!args.pipefd)
		return (NULL);
	i = 0;
	while (args.nb_pipe > i)
	{
		args.pipefd[i] = malloc(sizeof(int) * 2);
		if (!args.pipefd[i])
			return (NULL);
		i++;
	}
	return (args.pipefd);
}

void	exec_multi_pipe(char **env, t_pipe args, int i, int **pipefd)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		return (perror("fork "));
	if (pid == 0)
	{
		if (i == 0)
			dup2(pipefd[i][1], STDOUT_FILENO);
		else if (i == args.nb_pipe - 1)
			dup2(pipefd[i - 1][0], STDIN_FILENO);
		else
		{
			dup2(pipefd[i - 1][0], STDIN_FILENO);
			dup2(pipefd[i][1], STDOUT_FILENO);
		}
		close_pipe(args, pipefd);
		if (is_builtins(args.arg[0]) == 0)
			make_builtins(args, i);
		else
			execve(args.path, args.arg, env);
		exit(0);
	}
}

void	exec_multi_cmd(char **env, char **cmd, t_pipe args)
{
	int		i;
	int		**pipefd;

	args.nb_pipe = args.nb_pipe + 1;
	args.c_index = 0;
	args.path = NULL;
	pipefd = init_pipe(args);
	i = 0;
	while (args.nb_pipe > i)
	{
		pipe(pipefd[i]);
		i++;
	}
	i = 0;
	while (i < args.nb_pipe)
	{
		if (cmd[args.c_index] != NULL)
		{
			args.path = check_cmd(cmd[next_path(cmd, args.c_index)], env);
			if (!args.path)
				return ;
			args.arg = strdup_arg_execve(cmd, cmd[next_path(cmd, args.c_index)]);
		}
		else
		{
			args.path = NULL;
			args.arg = NULL;
		}
		if (args.outfile >= 0 && args.infile < 0)
			exec_multi_outfile(env, args, i, pipefd);
		else if (args.outfile >= 0 && args.infile >= 0)
			exec_multi_outfile_infile(env, args, i, pipefd);
		else if (args.infile >= 0 && args.outfile < 0)
			exec_multi_infile(env, args, i, pipefd);
		else if (cmd[args.c_index + 2] != cmd[found_infile(cmd)])
			exec_multi_pipe(env, args, i, pipefd);
		i++;
		if (i != args.nb_pipe)
		{
			args.c_index = next_path(cmd, args.c_index);
			args.c_index++;
		}
	}
	free(args.path);
	free_double_char(args.arg);
	close_pipe(args, pipefd);
	free_double_int(pipefd, args.nb_pipe);
}
