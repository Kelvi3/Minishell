/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 09:58:47 by tcazenav          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/02/01 08:35:19 by tcazenav         ###   ########.fr       */
=======
/*   Updated: 2023/01/31 11:35:53 by lulaens          ###   ########.fr       */
>>>>>>> a444e644d9d906733683704421baa7f09abc107c
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

<<<<<<< HEAD
typedef struct s_element
{
	char	**cmd;	
}				t_element;

char		*current_path(void);
void		condition_prompt(char *line);

//parse cmd
t_element	*parse_cmd(char *line);
char		**parse_cmd_bis(t_element arr, char *line);
=======
// signal
void	ft_signal(void);
void	ft_check_line(char *line);

char	*current_path(void);
>>>>>>> a444e644d9d906733683704421baa7f09abc107c

#endif
