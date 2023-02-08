/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:41:22 by tcazenav          #+#    #+#             */
/*   Updated: 2023/02/08 13:11:32 by tcazenav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*multi_pipe(char **cmd, char **env, int nb_pipe)
{
	(void) cmd;
	(void) env;
	(void) nb_pipe;
	return (NULL);
}

void	no_pipe(char **cmd, char **env)
{
	int		i;
	t_pipe	args;

	i = 0;
	printf("'%s'\n", cmd[0]);
	while (cmd[i])
		i++;
	if (cmd[0][0] == '<')
		args.infile = open(cmd[1], O_RDONLY);
	if (cmd[i - 1][0] == '>')
		args.outfile = open(cmd[i], O_RDWR | O_CREAT | O_TRUNC, 0664);
	if (cmd[i - 1][0] == '>' && cmd[0][0] == '<')
		printf("no pipe && infile && outfile\n");
	else if (cmd[0][0] == '<' && args.infile >= 0 && cmd[2] != NULL)
		exec_no_pipe_infile(args, env, cmd);
	else if (cmd[i - 1][0] == '>')
		printf("no pipe && outfile\n");
	else if (cmd[0][0] != '<')
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
