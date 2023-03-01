/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:59:33 by lulaens           #+#    #+#             */
/*   Updated: 2023/02/23 11:06:32 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <string.h>
#include <unistd.h>

int	g_exit_code = 0;

static void	ft_init_lst(t_list **envcp, t_list **export)
{
	*envcp = NULL;
	*export = NULL;
}

int	main(int argc, char **argv, char **env)
{
	char		*path;
	char		*line;
	char		**cmd;
	t_list		*envcp;
	t_list		*export;

	(void) argc;
	(void) argv;
	//printf("%s\n", env[0]);
	line = NULL;
	ft_init_lst(&envcp, &export);
	path = current_path();
	cmd = NULL;
	ft_signal();
	envcp = init_lst(envcp, env);
	export = init_lst(export, env);
	while (1)
	{
		line = readline("$>");
		if (line == NULL)
			break ;
		cmd = parse_cmd(line, cmd);
	/*	int	i = 0;
		while (cmd[i])
		{
			printf("cmd[%d] = %s\n", i, cmd[i]);
			i++;
		}*/
		if (is_pipe(cmd) == 1)
			parse_pipe(cmd, env);
		ft_check_line(line, envcp, export);
		ft_builtins(cmd, line, &envcp, &export);
		if (line)
			add_history(line);
		free_double_char(cmd);
		free(line);
		line = NULL;
	}
/* probleme double free export hello*/
/* free value de hello dans envcp alors que on lq print pas*/
/* voir ft_add_param dans export*/
//	printf("%s\n", envcp->next->name);
	free_lst(&envcp);
	free_lst(&export);
	free(path);
	return (0);
}
