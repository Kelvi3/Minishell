/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:35:42 by tcazenav          #+#    #+#             */
/*   Updated: 2023/03/01 17:48:02 by tcazenav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	next_path(char **cmd, int index)
{
	while (cmd[index][0] != '|' && cmd[index] != NULL)
		index++;
	return (index);
}

void	close_pipe(t_pipe args, int **pipefd)
{
	int	i;

	i = 0;
	while (args.nb_pipe > i)
	{
		close(pipefd[0][i]);
		close(pipefd[1][i]);
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
		execve(args.path, args.arg, env);
		exit(0);
	}
	free_double_char(args.arg);
	free(args.path);
}

void	exec_multi_cmd(char **env, char **cmd, t_pipe args)
{
	int		i;
	int		**pipefd;

	args.nb_pipe = args.nb_pipe + 1;
	args.c_index = 0;
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
		args.path = check_cmd(cmd[args.c_index], env);
		if (!args.path)
			return ;
		args.arg = strdup_arg_execve(cmd, cmd[args.c_index]);
		exec_multi_pipe(env, args, i, pipefd);
		i++;
		if (i != args.nb_pipe)
			args.c_index = next_path(cmd, args.c_index);
		if (i != args.nb_pipe)
			args.c_index++;
	}
	close_pipe(args, pipefd);
	free_double_int(pipefd, args.nb_pipe);
}
