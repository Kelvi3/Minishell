/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 09:58:47 by tcazenav          #+#    #+#             */
/*   Updated: 2023/02/16 09:31:33 by lulaens          ###   ########.fr       */
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
# include <limits.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_element
{
	char	**cmd;
	char	**envcp;
}				t_element;
/// TEST

void	ft_add_envv(char **env);


typedef struct s_pipe {
	int		infile;
	int		outfile;
	int		nb_cmd;
	char	*path;
}				t_pipe;
// ALL BUILTINS
void		ft_builtins(char **cmd, char **env, t_list **envcp, t_list **export);
// echo
void		ft_echo(char **cmd);

//cd 
void		ft_cd(char **cmd, char **env);

//pwd
void		ft_pwd(char **cmd);

// export
void	ft_export(char **args, t_list **envcpp, t_list **export);
void	ft_print_envcp(t_list *lst);
void	ft_swap_lst(t_list **tmp_i, t_list **tmp_j);
char	*ft_cpy_name(char *args);
char	*ft_cpy_value(char *args);
t_list	*init_lst(t_list *env_lst, char **env);
int		ft_check_name(char **args);
int		ft_check_double(t_list *new_env, t_list *envcp,  char **args);

// unset
void	ft_unset(char **key, t_list **export);
void	ft_unset_env(char **key, t_list **envcp);
int		ft_check_len(char *key, t_list **lst);
int		ft_check_lst_name(char *key, t_list **lst);
void	ft_swp(t_list **tmp, t_list **t_tmp, int flag);
// env
void		ft_env(t_list **envcp, char **cmd);

//exit
int			ft_exit(char **cmd, t_list **envcp, t_list **export);

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

char		*current_path(void);

char		**ft_init_env(char **env);

// utils
void		free_double_char(char **arg);
void		free_lst(t_list **lst);
char	*ft_strtok(char *str, const char *delim);
int		ft_len(char **str);
int		ft_check_alpha_export(char *args);

// pipe
int			is_pipe(char **cmd);
char		*is_executable(char *cmd, char **env);
char		*if_dir(char *car, char *str);
void		parse_pipe(char **cmd, char **env);
void		exec_no_pipe_infile(t_pipe args, char **env, char **cmd);
void		exec_simple_cmd(char **env, char **cmd);
char		*check_cmd(char *cmd, char *const *envp);
char		*fix_str(char *cmd, char c);
int			ft_strlento(char *str, char c);
char		*ft_strcat_cmd(char *s1, int size, char *s2);
int			ft_strchr_cmd(char *cmd, char c);

#endif
