/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:32:19 by tcazenav          #+#    #+#             */
/*   Updated: 2023/03/10 15:58:27 by tcazenav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**strdup_arg_execve(char **cmd, char *start)
{
	char	**arg;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (cmd[i] != start)
		i++;
	while (cmd[i + j] != NULL && cmd[i + j][0] != '|' && cmd[i + j][0] != '<'
			&& cmd[i + j][0] != '>')
	{
		j++;
	}
	arg = malloc(sizeof(char *) * (j + 1));
	if (!arg)
		return (NULL);
	j = 0;
	while (cmd[i + j] != NULL && cmd[i + j][0] != '|' && cmd[i + j][0] != '<'
			&& cmd[i + j][0] != '>')
	{
		arg[j] = malloc(sizeof(char) * (ft_strlen(cmd[i + j]) + 1));
		if (!arg[j])
			return (NULL);
		arg[j] = ft_strdup(cmd[i + j]);
		j++;
	}
	arg[j] = NULL;
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
	int		i;

	pipe(pipefd);
	i = 0;
	while (cmd[i])
		i++;
	while (i > 0)
	{
		if (cmd[i - 1][0] == '<')
			break ;
		i--;
	}
	if (cmd[i + 1] == NULL
		|| (cmd[found_infile(cmd)] == cmd[i + 1] && cmd[i + 2] == NULL))
	{
		arg = strdup_arg_execve(cmd, cmd[0]);
		args.path = check_cmd(cmd[0], env);
	}
	else
	{
		arg = strdup_arg_execve(cmd, cmd[i + 1]);
		args.path = check_cmd(cmd[i + 1], env);
	}
	if (!arg || !args.path)
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
