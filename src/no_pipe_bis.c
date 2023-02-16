/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_pipe_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:29:58 by tcazenav          #+#    #+#             */
/*   Updated: 2023/02/09 14:38:30 by tcazenav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	exec_outfile(t_pipe args, char **arg, char **env, int *pipefd)
{
	dup2(args.outfile, STDOUT_FILENO);
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	execve(args.path, arg, env);
	close(args.outfile);
}

static void	exec_infile(t_pipe args, char **arg, char **env, int *pipefd)
{
	dup2(args.infile, STDIN_FILENO);
	close(pipefd[0]);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	execve(args.path, arg, env);
	close(args.infile);
}

void	exec_no_pipe_outfile(t_pipe args, char **env, char **cmd)
{
	int		pid;
	char	**arg;
	int		pipefd[2];

	pipe(pipefd);
	if (cmd[1][0] == '-')
		arg = strdup_arg_execve(cmd[0], cmd[1]);
	else
		arg = strdup_arg_execve(cmd[0], NULL);
	if (!arg)
		return ;
	args.path = check_cmd(cmd[0], env);
	if (!args.path)
		return ;
	pid = fork();
	if (pid < 0)
		return (perror("fork "));
	if (pid == 0)
		exec_outfile(args, arg, env, pipefd);
	wait(0);
	close(pipefd[0]);
	close(pipefd[1]);
	close(args.outfile);
	free_double_char(arg);
	free(args.path);
}

void	exec_no_pipe(t_pipe args, char **arg, char **env)
{
	int	pid;
	int	pid2;
	int	pipefd[2];
	int	status;

	pipe(pipefd);
	pid = fork();
	if (pid < 0)
		return (perror("fork "));
	if (pid == 0)
		exec_infile(args, arg, env, pipefd);
	waitpid(pid, &status, 0);
	pid2 = fork();
	if (pid2 < 0)
		return (perror("fork "));
	if (pid2 == 0)
	{
		dup2(args.outfile, STDOUT_FILENO);
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
	}
	close(pipefd[0]);
	close(pipefd[1]);
	wait(0);
	free(args.path);
}

void	exec_no_pipe_outfile_infile(t_pipe args, char **env, char **cmd)
{
	char	**arg;

	if (cmd[3][0] == '-')
		arg = strdup_arg_execve(cmd[2], cmd[3]);
	else
		arg = strdup_arg_execve(cmd[2], NULL);
	if (!arg)
		return ;
	args.path = check_cmd(cmd[2], env);
	if (!args.path)
		return ;
	exec_no_pipe(args, arg, env);
	close(args.infile);
	close(args.outfile);
	free_double_char(arg);
}
