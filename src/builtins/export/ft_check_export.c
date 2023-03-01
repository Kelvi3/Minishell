/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:18:25 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/01 12:47:11 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static void	print_error(char *args)
{
	(void)args;
//	ft_putstr_fd("bash: export: ", 2);
//	ft_putstr_fd(args, 2);
	ft_putstr_fd(" not a valid identifier\n", 2);
}

int	ft_check_name(char **args)
{
	int	i;
	int	j;

	i = 1;
	while (args[i])
	{
		j = 0;
	//	printf("%s\n", args[i]);
		if (ft_isalpha(args[i][0]) == 0 && args[i][0] != '_')
		{
			print_error(args[i]);
			return (1);
		}
		while (args[i][j] && args[i][j] != '=')
		{
			if (ft_isalnum(args[i][j]) == 0 && args[i][j] != '_')
			{
				print_error(args[i]);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static	int	ft_add_value(t_list *tmp, char *args)
{
	if (ft_strncmp(args, tmp->name, ft_strlen(tmp->name)) == 0)
	{
		if (!ft_strchr(args, '='))
			return (1);
		tmp->value = ft_cpy_value(args);
		return (1);
	}
	return (0);
}

int	ft_check_double(t_list *lst, char **args)
{
	int		i;
	char	*name;
	t_list	*tmp;

	tmp = lst;
	i = 1;
	while (args[i])
	{
		tmp = lst;
		name = ft_cpy_name(args[i]);
		while (tmp)
		{
			if (ft_add_value(tmp, args[i]) == 1)
				return (1);
			tmp = tmp->next;
		}
		free(name);
		i++;
	}
	return (0);
}
