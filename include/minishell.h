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
	int		**pipefd;
	int		infile;
	int		outfile;
	char	*path;
	int		nb_pipe;
	int		nb_cmd;
	int		c_index;
	char	**arg;
}				t_pipe;
// ALL BUILTINS
void		ft_builtins(char **cmd, char **env);
// echo
void		ft_echo(char **cmd);

//cd 
void		ft_cd(char **cmd, char **env);

//pwd
void		ft_pwd(char **cmd);

// export
void	ft_export(char **env, char **args, t_list *envcp);
void	ft_print_envcp(t_list **lst);
t_list	*init_lst(t_list *env_lst, char **env);
t_list	*ft_add_param_env(t_list *new_env, char **args);
int		ft_check_name(char **args);
void	ft_add_lst(t_list **env_lst, char *name, char *value);
void	ft_sort_ascii(t_list **lst);

// unset
t_list	*ft_unset(t_list *envcp, char **key);

// env
void		ft_env(t_list *envcp, char **cmd);

//exit
int			ft_exit(char **cmd);

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
char	*ft_strtok(char *str, const char *delim);
int		ft_len(char **str);
int		ft_check_alpha_export(char *args);
void	free_double_int(int **arg, int len);
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
void		exec_no_pipe_outfile(t_pipe args, char **env, char **cmd);
char		**strdup_arg_execve(char *cmd1, char *cmd2);
void		exec_no_pipe_outfile_infile(t_pipe args, char **env, char **cmd);
void		exec_multi_cmd(char **env, char **cmd, t_pipe args);
//error
void	ft_put_error(char *str, char *cmd);


#endif
