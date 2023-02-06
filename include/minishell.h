/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 09:58:47 by tcazenav          #+#    #+#             */
/*   Updated: 2023/02/06 13:09:33 by tcazenav         ###   ########.fr       */
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
#include <fcntl.h>

typedef struct s_element
{
	char	**cmd;	
}				t_element;

typedef struct s_pipe {
	int		infile;
	int		outfile;
	int		nb_cmd;
}				t_pipe;

char		*current_path(void);
void		condition_prompt(char *line);

//parse cmd
char		**parse_cmd(char *line, char **cmd);
char		**parse_cmd_bis(char **cmd, char *line, int word);
int			count_no_delim(char *line, int i);
int			count_squote(char *line, int i);
int			count_dquote(char *line, int i);
int			ft_sep(char *line, int i, int len);

// signal
void		ft_signal(void);
void		ft_check_line(char *line);

// built
// env
void		ft_env(char **env, char *line);

char		*current_path(void);

char		**ft_init_env(char **env);

// utils
char		*ft_strtok(char *str, const char *delim);

// pipe
int			is_pipe(char **cmd);
char		*is_executable(char *cmd, char **env);
char		*if_dir(char *car, char *str);
char		*parse_pipe(char **cmd, char **env);
void		exec_no_pipe_infile(t_pipe args, char **env);
void		exec_no_pipe_infile(t_pipe args, char **env);

#endif
