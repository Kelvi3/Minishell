/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:41:22 by tcazenav          #+#    #+#             */
/*   Updated: 2023/02/17 10:29:42 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	multi_pipe(char **cmd, char **env, int nb_pipe)
{
	int		i;
	t_pipe	args;

	i = 0;
	args.nb_pipe = nb_pipe;
	while (cmd[i])
		i++;
	if (cmd[0][0] == '<')
		args.infile = open(cmd[1], O_RDONLY);
	if (i - 2 >= 0 && cmd[i - 2][0] == '>')
		args.outfile = open(cmd[i - 1], O_RDWR | O_CREAT | O_TRUNC, 0664);
	if (i - 2 >= 0 && cmd[i - 2][0] == '>' && cmd[0][0] == '<'
		&& args.infile >= 0 && args.outfile >= 0)
		printf("MULTI PIPE INFILE OUTFILE\n");
	else if (cmd[2] && cmd[0][0] == '<' && args.infile >= 0 && cmd[2] != NULL)
		printf("MULTI PIPE INFILE\n");
	else if (i - 2 >= 0 && cmd[i - 2][0] == '>' && args.outfile >= 0)
		printf("MULTI PIPE OUTFILE\n");
	else
		exec_multi_cmd(env, cmd, args);
	i = 0;
	while (i < args.nb_pipe)
	{
		waitpid(-1, NULL, 0);
		i++;
	}
}

void	no_pipe(char **cmd, char **env)
{
	int		i;
	t_pipe	args;

	i = 0;
	while (cmd[i])
		i++;
	if (cmd[0][0] == '<')
		args.infile = open(cmd[1], O_RDONLY);
	if (i - 2 >= 0 && cmd[i - 2][0] == '>')
		args.outfile = open(cmd[i - 1], O_RDWR | O_CREAT | O_TRUNC, 0664);
	if (i - 2 >= 0 && cmd[i - 2][0] == '>' && cmd[0][0] == '<'
		&& args.infile >= 0 && args.outfile >= 0)
		exec_no_pipe_outfile_infile(args, env, cmd);
	else if (cmd[2] && cmd[0][0] == '<' && args.infile >= 0 && cmd[2] != NULL)
		exec_no_pipe_infile(args, env, cmd);
	else if (i - 2 >= 0 && cmd[i - 2][0] == '>' && args.outfile >= 0)
		exec_no_pipe_outfile(args, env, cmd);
	else
		exec_simple_cmd(env, cmd);

}

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
