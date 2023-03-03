/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:32:19 by tcazenav          #+#    #+#             */
/*   Updated: 2023/03/02 13:27:11 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**strdup_arg_execve(char *cmd1, char *cmd2)
{
	char	**arg;

	arg = malloc(sizeof(char *) * 3);
	if (!arg)
		return (NULL);
	arg[0] = malloc(sizeof(char) * (ft_strlen(cmd1) + 1));
	if (!arg[0])
		return (NULL);
	arg[0] = ft_strdup(cmd1);
	arg[1] = NULL;
	if (cmd2 != NULL && cmd2[0] == '-')
	{		
		arg[1] = malloc(sizeof(char) * (ft_strlen(cmd2) + 1));
		if (!arg[1])
			return (NULL);
		arg[1] = ft_strdup(cmd2);
	}
	arg[2] = NULL;
	return (arg);
}

char	**strdup_arg_execve_flag(char *cmd, int index)
{
	char	**arg;
	int		i;

	i = 0;
	arg = NULL;
	while (cmd[i] != '\0')
		i++;
	arg[index] = malloc(sizeof(char) * (i + 1));
	if (!arg)
		return (NULL);
	i = 0;
	while (cmd[i] != '\0')
	{
		arg[index][i] = cmd[i];
		i++;
	}
	arg[index][i] = '\0';
	return (arg);
}

void	exec_infile(t_pipe args, char **arg, char **env, int *pipefd)
{
	dup2(args.infile, STDIN_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	execve(args.path, arg, env);
	close(args.infile);
}

void	exec_no_pipe_infile(t_pipe args, char **env, char **cmd)
{
	int		pid;
	char	**arg;
	int		pipefd[2];

	pipe(pipefd);
	arg = strdup_arg_execve(cmd[2], cmd[3]);
	if (!arg)
		return ;
	args.path = check_cmd(cmd[2], env);
	if (!args.path)
		return ;
	pid = fork();
	if (pid < 0)
		return (perror("fork "));
	if (pid == 0)
		exec_infile(args, arg, env, pipefd);
	wait(0);
	close(pipefd[0]);
	close(pipefd[1]);
	close(args.infile);
	free_double_char(arg);
	free(args.path);
}

/* envoyer la copie de env au lieu du vrai env */

void	exec_simple_cmd(char **env, char **cmd)
{
	int		pid;
	char	*path;
	int		i;

	i = 0;
	path = check_cmd(cmd[0], env);
	if (!path)
	{
		g_exit_code = 127;
		ft_put_error(": command not found\n", cmd[0]);
		free(path);
		return ;
	}
	pid = fork();
	if (pid < 0)
		return (perror("fork "));
	if (pid == 0)
		execve(path, cmd, env);
	wait(0);
	free(path);
}
