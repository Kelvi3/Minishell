/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtok.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 07:55:48 by lulaens           #+#    #+#             */
/*   Updated: 2023/02/01 08:34:51 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_strtok(char *str, const char *delim)
{
	static int	current_position = 0;
	static char	*string = NULL;
	int			start;

	if (str != NULL)
	{
		current_position = 0;
		string = str;
	}
	if (string == NULL || string[current_position] == '\0')
		return (NULL);
	start = current_position;
	while (string[current_position] != '\0')
	{
		if (ft_strchr(delim, string[current_position]) != NULL)
		{
			string[current_position] = '\0';
			current_position++;
			break ;
		}
		current_position++;
	}
	return (&string[start]);
}
