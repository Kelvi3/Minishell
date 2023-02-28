#include "../include/minishell.h"

void	free_double_char(char **arg)
{
	int	i;

	i = 0;
	while (arg && arg[i])
	{
		free(arg[i]);
		arg[i] = NULL;
		i++;
	}
	free(arg);
	arg = NULL;
}

void	free_lst(t_list **lst)
{
	while (*lst)
	{
		free((*lst)->name);
		free((*lst)->value);
		*lst = (*lst)->next;
	}
	free(*lst);
	*lst = NULL;
}

void	free_double_int(int **arg, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(arg[i]);
		i++;
	}
	free(arg);
}
