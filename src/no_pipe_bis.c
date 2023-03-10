/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_pipe_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:29:58 by tcazenav          #+#    #+#             */
/*   Updated: 2023/03/14 08:56:05 by tcazenav         ###   ########.fr       */
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

/*void	exec_infile(t_pipe args, char **arg, char **env, int *pipefd)
{
	dup2(args.infile, STDIN_FILENO);
	close(pipefd[0]);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	execve(args.path, arg, env);
	close(args.infile);
}*/

void	exec_no_pipe_outfile(t_pipe args, char **env, char **cmd)
{
	int		pid;
	char	**arg;
	int		pipefd[2];

	pipe(pipefd);
	arg = strdup_arg_execve(cmd, cmd[0]);
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
	//int	status;

	pipe(pipefd);
	pid = fork();
	if (pid < 0)
		return (perror("fork "));
	if (pid == 0)
	{
		dup2(pipefd[1], STDOUT_FILENO);
		dup2(args.infile, STDIN_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		execve(args.path, arg, env);
		close(args.infile);
		//close(args.outfile);
		//exec_infile(args, arg, env, pipefd);
	}
	//waitpid(pid, &status, 0);
	pid2 = fork();
	if (pid2 < 0)
		return (perror("fork "));
	if (pid2 == 0)
	{
		dup2(pipefd[0], STDIN_FILENO);
		dup2(args.outfile, STDOUT_FILENO);
		//close(args.infile);
		close(pipefd[0]);
		//close(args.outfile);
		close(pipefd[1]);
		/*close(0);
		close(1);*/
	}
	close(pipefd[0]);
	close(pipefd[1]);
	//waitpid(pid2, &status, 0);
	free(args.path);
}

void	exec_no_pipe_outfile_infile(t_pipe args, char **env, char **cmd)
{
	char	**arg;
	int		i;
	i = 0;
	while (cmd[i])
		i++;
	i--;
	while (i > 0)
	{
		if (cmd[i][0] == '<')
			break ;
		i--;
	}
	arg = strdup_arg_execve(cmd, cmd[i - 1]);
	if (!arg)
		return ;
	args.path = check_cmd(cmd[i - 1], env);
	if (!args.path)
		return ;
	exec_no_pipe(args, arg, env);
	waitpid(-1, NULL, 0);
	waitpid(-1, NULL, 0);
	close(args.infile);
	close(args.outfile);
	free_double_char(arg);
}
