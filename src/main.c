/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:59:33 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/01 16:13:42 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <string.h>
#include <unistd.h>

int	g_exit_code = 0;

static void	ft_init_lst(t_list **envcp, t_list **export, char **env)
{
	*envcp = NULL;
	*export = NULL;
	init_env(envcp, env);
	init_env(export, env);
}

int	main(int argc, char **argv, char **env)
{
	t_list		*lst;
	t_list		*export;

	(void) argc;	
	(void) argv;
	ft_init_lst(&lst, &export, env);
	lst->path = current_path();
	ft_signal();
	while (1)
	{
		lst->line = readline("$>");
		if (lst->line == NULL)
			break ;
		parse_cmd(&lst);
		if (is_pipe(lst->cmd) == 1)
			parse_pipe(lst->cmd, env);
		ft_check_line(lst->line, lst, export);
		ft_builtins(lst->cmd, lst->line, &lst, &export);
		if (lst->line)
			add_history(lst->line);
		free_double_char(lst->cmd);
		free(lst->line);
		lst->line = NULL;
	}
	free_lst(&lst);
	free_lst(&export);
	free(lst->path);
	return (0);
}

/* probleme double free export hello*/
/* free value de hello dans envcp alors que on lq print pas*/
/* voir ft_add_param dans export*/
//	printf("%s\n", envcp->next->name);
