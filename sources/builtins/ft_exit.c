#include "../../includes/minishell.h"

int	ft_exit(char *args)
{
	t_minishell shell;
    int	status;
	//int	i;
	//int	number;

    shell = *get_minishell(NULL);
    (void)args;
	//i = 0;
	status = get_status(-1);
    rl_clear_history();
	free_minishell(&shell);
	exit (status);
}
