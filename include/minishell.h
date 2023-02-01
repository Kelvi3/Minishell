/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 09:58:47 by tcazenav          #+#    #+#             */
/*   Updated: 2023/02/01 09:06:19 by lulaens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include "../libft/libft.h"

typedef struct s_element
{
	char	**cmd;	
}				t_element;

char		*current_path(void);
void		condition_prompt(char *line);

//parse cmd
t_element	*parse_cmd(char *line);
char		**parse_cmd_bis(t_element arr, char *line);

// signal
void	ft_signal(void);
void	ft_check_line(char *line);

// built
// env
void	ft_env(char **env, char *line);


char	*current_path(void);

char	**ft_init_env(char **env);

// utils
char	*ft_strtok(char *str, const char *delim);
#endif
