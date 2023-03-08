/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:59:33 by lulaens           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/03/08 09:39:55 by tcazenav         ###   ########.fr       */
=======
/*   Updated: 2023/03/07 16:31:43 by lulaens          ###   ########.fr       */
>>>>>>> 3370d8d627793fdbd883e8f37941cea34d03f960
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

/* a faire : 
 * -copie de env
 * -indexer les builtins
 * -voir pour implementer builtins dans les pipes
 * -normer echo et export*/
int	main(int argc, char **argv, char **env)
{
	t_list		*lst;
	t_list		*export;
	int			i;

	i = 0;
	(void) argc;	
	(void) argv;
	ft_init_lst(&lst, &export, env);
	lst->path = current_path();
	ft_signal();
	while (1)
	{
		i = 0;
		lst->line = readline("$>");
		if (lst->line == NULL)
			break ;
		parse_cmd(&lst);
<<<<<<< HEAD
		/*while (lst->cmd[i])
		{
			printf("cmd[%i] = '%s'\n", i, lst->cmd[i]);
			i++;
		}*/
=======
	/*	while (lst->cmd[i])
		{
			printf("cmd[%d] %s\n", i, lst->cmd[i]);
			i++;
		}*/
		i = 0;
>>>>>>> 3370d8d627793fdbd883e8f37941cea34d03f960
		if (is_pipe(lst->cmd) == 1)
			parse_pipe(lst->cmd, env);
		ft_check_line(lst, export);
		ft_builtins(&lst, &export);
		if (lst->line)
			add_history(lst->line);
		free_double_char(lst->cmd);
		free(lst->line);
		lst->line = NULL;
	}
	/* probleme free lst env invalid read of size */
//	free_lst(&lst);
	free_lst(&export);
	free(lst->path);
	return (0);
}

/* probleme double free export hello*/
/* free value de hello dans envcp alors que on lq print pas*/
/* voir ft_add_param dans export*/
//	printf("%s\n", envcp->next->name);
