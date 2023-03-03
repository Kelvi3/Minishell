/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 08:56:40 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/03 12:59:21 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	pass_dquote_squote(t_list **envcp, int i)
{
	t_list	*lst;

	lst = *envcp;
	while (lst->line[i] == '\'' || lst->line[i] == '"')
		i++;
	return (i);
}

/* parse cmd echo */

char	*ft_check_after(t_list **envcp, int i)
{
	t_list	*lst;
	char	*tmp;
	int		j;

	j = 0;
	tmp = malloc(sizeof(char) * (5));
	if (!tmp)
		return (NULL);
	lst = *envcp;
	tmp[j++] = lst->line[i++];
	i = pass_dquote_squote(envcp, i);
	if (lst->line[i] == 'c')
		tmp[j++] = lst->line[i++];
	i = pass_dquote_squote(envcp, i);
	if (lst->line[i] == 'h')
		tmp[j++] = lst->line[i++];
	i = pass_dquote_squote(envcp, i);
	if (lst->line[i] == 'o')
		tmp[j++] = lst->line[i++];
	tmp[j] = '\0';
	return (tmp);
}
/* compter nombre de cote ou guillemet pour print jusk ce nombre */

int	check_param_n(t_list **envcp, int i)
{
	t_list	*lst;

	lst = *envcp;
	i = pass_dquote_squote(envcp, i);
	if (lst->line[i] == '-')
	{
		i++;
		while (lst->line[i] && lst->line[i] != ' ')
		{
			if (lst->line[i] != 'n')
				return (0);
			i++;
		}
	}
	else
		return (0);
	return (i);
}
void	print_echo(t_list **envcp, int i)
{
	t_list	*lst;
	int		count;
	int		space;
	int		flag;

	flag = 0;
	count = 0;
	lst = *envcp;
	space = count_nb_space(envcp, i);
	i = pass_dquote_squote(envcp, i);
	while (lst->line[i] && lst->line[i] != ' ')
		i++;
	while (lst->line[i] && lst->line[i] == ' ')
		i++;
	/* check si ya un -n, flag == 0 pour le \n */
	if (check_param_n(envcp, i) != 0)
	{
		i = check_param_n(envcp, i);
		while (lst->line[i] && lst->line[i] == ' ')
			i++;
		flag = 1;
	}
	/* retourner i a chaque print, ou envoyer un l'adresse */
	if (lst->line[i] == '"')
		print_dquote(envcp, i, count, space);
	else if (lst->line[i] == '\'')
		print_squote(envcp, i);
	else
		print_noquote(envcp, i, space);
	if (flag == 0)
		printf("\n");
}

void	ft_echo(t_list **envcp)
{
	t_list	*lst;
	char	*tmp;
	int		i;

	i = 0;
	lst = *envcp;
	tmp = NULL;
	while (lst->line[i])
	{
		if (lst->line[i] == 'e')
		{
			tmp = ft_check_after(envcp, i);
			if (ft_strcmp(tmp, "echo") == 0)
			{
				print_echo(envcp, i);
				break ;
			}	
		}
		i++;
	}
	free(tmp);
}
