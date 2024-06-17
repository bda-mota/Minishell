#include "../../includes/minishell.h"

int	ft_exit(char *args)
{
	t_minishell	shell;
	int			status;

    (void)args;
	shell = *get_minishell(NULL);
	status = get_status(-1);
	rl_clear_history();
	free_minishell(&shell);
	exit (status);
}
