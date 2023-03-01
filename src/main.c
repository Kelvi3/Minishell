/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:59:33 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/01 15:34:54 by lulaens          ###   ########.fr       */
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
	t_list		*lst;
	t_list		*export;

	(void) argc;
	(void) argv;
	ft_init_lst(&lst, &export);
	path = current_path();
	line = NULL;
	cmd = NULL;
	ft_signal();
	init_lst(&lst, env);
	init_lst(&export, env);
	while (1)
	{
		line = readline("$>");
		if (line == NULL)
			break ;
		parse_cmd(line, &lst);
	
		/*printf("%s\n", lst->cmd[0]);
		if (is_pipe(lst->cmd) == 1)
			parse_pipe(cmd, env);
		ft_check_line(line, lst, export);
		ft_builtins(lst->cmd, line, &lst, &export);
		if (line)
			add_history(line);
		free_double_char(cmd);
		free(line);
		line = NULL;*/
	}
	free_lst(&lst);
	free_lst(&export);
	free(path);
	return (0);
}

/* probleme double free export hello*/
/* free value de hello dans envcp alors que on lq print pas*/
/* voir ft_add_param dans export*/
//	printf("%s\n", envcp->next->name);
