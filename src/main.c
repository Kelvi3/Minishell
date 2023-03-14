/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:59:33 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/14 10:17:29 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <string.h>
#include <unistd.h>

int	g_exit_code = 0;

static t_data	*ft_init_lst(void)
{
	t_data	*dt;

	dt = malloc(sizeof(t_data));
	return (dt);
}

int	main(int argc, char **argv, char **env)
{
	t_data	*data;
	int			i;

	i = 0;
	(void) argc;	
	(void) argv;
	data = NULL;
	data = ft_init_lst();
	init_env(&data->envcp, env);
	init_env(&data->export, env);
	data->envcpy = cpy_env_execve(data);
/*	while (data->export)
	{
		printf("%s\n", data->export->name);
		data->export = data->export->next;
	}*/
	//	ft_signal();
	while (1)
	{
		i = 0;
		data->line = readline("$>");
		if (data->line == NULL)
			break ;
		if (data->line[0] == '\0')
			continue ;
		parse_cmd(&data);
		var_value(&data);
		/*while (data->cmd[i])
		{
			printf("cmd[%i] = '%s'\n", i, data->cmd[i]);
			i++;
		}*/
		i = 0;
		if (is_pipe(data->cmd) == 1)
			parse_pipe(data->cmd, data->envcpy);
		//ft_check_line(data, export);
		ft_builtins(&data);
		if (data->line)
			add_history(data->line);
		//free_double_char(data->cmd);
		free(data->line);
		data->line = NULL;
	}
//	free_lst(&lst);
//	free_double_char(data->envcpy);
	//free_lst(&export);
//	free(data->path);
	return (0);
}

/* probleme double free export hello*/
/* free value de hello dans envcp alors que on lq print pas*/
/* voir ft_add_param dans export*/
//	printf("%s\n", envcp->next->name);
