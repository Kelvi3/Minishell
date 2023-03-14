/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipe_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:35:57 by tcazenav          #+#    #+#             */
/*   Updated: 2023/03/10 12:39:41 by tcazenav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	exec_multi_outfile_infile(char **env, t_pipe args, int i, int **pipefd)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		return (perror("fork "));
	if (pid == 0)
	{
		if (i == 0)
		{
			dup2(args.infile, STDIN_FILENO);
			dup2(pipefd[i][1], STDOUT_FILENO);
		}
		else if (i == args.nb_pipe - 1)
		{
			dup2(pipefd[i - 1][0], STDIN_FILENO);
			dup2(args.outfile, STDOUT_FILENO);
		}
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

void	exec_multi_outfile(char **env, t_pipe args, int i, int **pipefd)
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
		{
			dup2(pipefd[i - 1][0], STDIN_FILENO);
			dup2(args.outfile, STDOUT_FILENO);
		}
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

void	exec_multi_infile(char **env, t_pipe args, int i, int **pipefd)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		return (perror("fork "));
	if (pid == 0)
	{
		if (i == 0)
		{
			dup2(args.infile, STDIN_FILENO);
			dup2(pipefd[i][1], STDOUT_FILENO);
		}
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
