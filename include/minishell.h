/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 09:58:47 by tcazenav          #+#    #+#             */
/*   Updated: 2023/02/01 08:54:31 by lulaens          ###   ########.fr       */
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
