/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:00:26 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/01 16:13:29 by lulaens          ###   ########.fr       */
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

extern int	g_exit_code;

/* TEST */
int		ft_quote_value(char *line);
char	*test_export(char *line);
char	*ft_check_doll(char **cmd, t_list **envcp, int j);
void	ft_add_envv(char **env);

/* voir pour faire une copy de envcp dans un char **
 dans la structure s_pipe */

typedef struct s_pipe {
	int		**pipefd;
	int		infile;
	int		outfile;
	char	*path;
	int		nb_pipe;
	int		nb_cmd;
	int		c_index;
	char	**arg;
}				t_pipe;
/* TEST */
void	ft_copy_envcp_in_struct(t_list **envcp);
int		check_pipe(char **cmd);
// ALL BUILTINS
void	ft_builtins(char **cmd, char *line, t_list **envcp, t_list **export);

/* ECHO */
void	ft_echo(char **cmd, t_list **envcp, char *line);
void	ft_print_var(char **cmd, t_list **envcp);
int		check_cote_echo(char *line);
int		ft_check_n(char *cmd);
int		ft_pass_n(char *line, int i);
int		ft_len_var(char *line);
int		ft_value_k(char **cmd);

/* CD */
void	ft_cd(char **cmd, t_list **envcp);

/* PWD */
void	ft_pwd(char **cmd, t_list **envcp);

/* EXPORT */
void	ft_export(char **args, char *line, t_list **envcpp, t_list **export);
void	ft_print_envcp(t_list *lst);
void	ft_swap_lst(t_list **tmp_i, t_list **tmp_j);
char	*ft_cpy_name(char *args);
char	*ft_cpy_value(char *args);
int		ft_check_name(char **args);
int		ft_check_double(t_list *lst, char **args);
void	init_env(t_list **env_lst, char **env);

/* UNSET */
void	ft_unset(char **key, t_list **export, int flag);
void	ft_unset_env(char **key, t_list **envcp);
void	ft_swp(t_list **tmp, t_list **t_tmp, int flag);
int		ft_check_len(char *key, t_list **lst);
int		ft_check_lst_name(char *key, t_list **lst);
int		ft_check_unset_arg(char *key, int flag);

/* ENV */
void	ft_env(t_list **envcp, char **cmd);

/* EXIT */
int		ft_exit(char **cmd, t_list **envcp, t_list **export);
char	*current_path(void);
void	condition_prompt(char *line);

/* PARSE CMD */
void	parse_cmd(t_list **lst);
void	parse_cmd_bis(t_list **lst, int word);
int		count_no_delim(char *line, int i);
int		count_squote(char *line, int i);
int		count_dquote(char *line, int i);
int		ft_sep(char *line, int i, int len);

/* SIGNAL */
void	ft_signal(void);
void	ft_check_line(char *line, t_list *envcp, t_list *export);

//////
char	*current_path(void);

/* UTILS */
void	free_double_int(int **arg, int len);
void	free_double_char(char **arg);
void	free_lst(t_list **lst);
char	*ft_strtok(char *str, const char *delim);
int		ft_len(char **str);
int		ft_check_alpha_export(char *args);

/* PIPE */
int		is_pipe(char **cmd);
int		ft_strlento(char *str, char c);
int		ft_strchr_cmd(char *cmd, char c);
char	*is_executable(char *cmd, char **env);
char	*if_dir(char *car, char *str);
char	*check_cmd(char *cmd, char *const *envp);
char	*fix_str(char *cmd, char c);
char	*ft_strcat_cmd(char *s1, int size, char *s2);
char	**strdup_arg_execve(char *cmd1, char *cmd2);
void	exec_no_pipe_outfile(t_pipe args, char **env, char **cmd);
void	exec_simple_cmd(char **env, char **cmd);
void	parse_pipe(char **cmd, char **env);
void	exec_no_pipe_infile(t_pipe args, char **env, char **cmd);
void	exec_no_pipe_outfile_infile(t_pipe args, char **env, char **cmd);
void	exec_multi_cmd(char **env, char **cmd, t_pipe args);

/* ERROR */
void	ft_put_error(char *str, char *cmd);

char	*ft_strtok(char *str, const char *delim);
#endif
