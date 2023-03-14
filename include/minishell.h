/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulaens <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:00:26 by lulaens           #+#    #+#             */
/*   Updated: 2023/03/14 11:10:58 by lulaens          ###   ########.fr       */
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
void	ft_add_envv(char **env);

/* voir pour faire une copy de envcp dans un char **
 dans la structure s_pipe */

typedef struct s_list
{
	char			*name;
	char			*value;
	struct s_list	*next;
}				t_list;

typedef struct s_data
{
	char		**cmd;
	char		*echo;
	char		**envcpy;
	int			size;
	int			flag;
	int			len;
	char		*line;
	t_list		*envcp;
	t_list		*export;
}				t_data;

typedef struct s_pipe {
	int				**pipefd;
	int				infile;
	int				outfile;
	char			*path;
	int				nb_pipe;
	int				nb_cmd;
	int				c_index;
	char			**arg;
	struct s_list	*exec;
}				t_pipe;

int		ft_lst_size(t_list *lst);
void	ft_lstaddfront(t_list **lst, t_list *new);
char	*ft_doll_env(char **cmd, t_data **envcp, int j);
char	**cpy_env_execve(t_data *data);
/* TEST */
void	ft_copy_envcp_in_struct(t_list **envcp);
int		check_pipe(char **cmd);
// ALL BUILTINS
void	ft_builtins(t_data **data);

/* ECHO */
void	var_value(t_data **envcp);
void	ft_echo(t_data **envcp);
int		ft_len_echo_arg(t_data **envcp, int i);
void	cpy_var_env(t_data *lst, int *i, int *j, int *c);
void	check_flag_for_quote(t_data *lst, int *i, int *j);
void	ft_cpy_cmd(t_data **envcp, int i);
char	*search_varrr(t_data **envcp, int len_ar, int start, int i);
/* utils */
int		pass_space(t_data **envcp, int i);
int		pass_dquote_squote(t_data **envcp, int i);
/* syntax */
int		ft_check_syntax(t_list **envcp, int i);
void	ft_print_var(char **cmd, t_list **envcp);
int		check_cote_echo(char *line);
int		ft_check_n(char *cmd);
int		ft_pass_n(char *line, int i);
int		ft_len_var(char *line);
int		ft_value_count(char **cmd);

/* CD */
void	ft_cd(t_data **envcp);

/* PWD */
void	ft_pwd(void);

/* EXPORT */
void	ft_export(t_data **envcp);
void	ft_print_envcp(t_list *lst);
void	ft_swap_lst(t_list **tmp_i, t_list **tmp_j);
char	*ft_cpy_name(char *args);
char	*ft_cpy_value(char *args);
int		ft_check_name(char **args);
int		ft_check_double(t_list *lst, char **args);
void	init_env(t_list **env_lst, char **env);

/* UNSET */
void	ft_unset(char **key, t_list **export, int flag, t_data **data);
void	ft_unset_env(char **key, t_list **envcp);
void	ft_swp(t_list **tmp, t_list **t_tmp, int flag);
int		ft_check_len(char *key, t_list **lst);
int		ft_check_lst_name(char *key, t_list **lst);
int		ft_check_unset_arg(char *key, int flag);

/* ENV */
void	ft_env(t_data **envcp);

/* EXIT */
int		ft_exit(char **cmd, t_list **envcp, t_list **export);
int		ft_check_digit(char *cmd);
int		exit_atol(char *cmd, long digit, t_list **envcp, t_list **export);
char	*current_path(void);
void	free_exit(t_list **envcp, t_list **export);
void	condition_prompt(char *line);

/* PARSE CMD */
void	parse_cmd(t_data **lst);
void	parse_cmd_bis(t_data **lst, int word);
int		count_no_delim(char *line, int i);
int		count_squote(char *line, int i);
int		count_dquote(char *line, int i);
int		ft_sep(char *line, int i, int len);

/* SIGNAL */
void	ft_signal(void);
void	ft_check_line(t_data *lst, t_data *export);

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
char	**strdup_arg_execve(char **cmd, char *start);
void	exec_no_pipe_outfile(t_pipe args, char **env, char **cmd);
void	exec_simple_cmd(char **env, char **cmd);
void	parse_pipe(char **cmd, char **env);
void	exec_no_pipe_infile(t_pipe args, char **env, char **cmd);
void	exec_no_pipe_outfile_infile(t_pipe args, char **env, char **cmd);
void	exec_multi_cmd(char **env, char **cmd, t_pipe args);
void	exec_multi_outfile_infile(char **env, t_pipe args, int i, int **pipefd);
void	exec_multi_infile(char **env, t_pipe args, int i, int **pipefd);
void	exec_multi_outfile(char **env, t_pipe args, int i, int **pipefd);
int		if_in_no_out(char **cmd);
int		if_in_a_out(char **cmd);
int		found_infile(char **cmd);
int		check_file(char *file);
void	close_pipe(t_pipe args, int **pipefd);

/* ERROR */
void	ft_put_error(char *str, char *cmd);
void	ft_err_syntax(char **cmd);

char	*ft_strtok(char *str, const char *delim);
#endif
