#include "../../includes/minishell.h"

static int	ft_exit_aux(char *args);

int	ft_exit(char *args)
{
	t_minishell	shell;
	int			status;

	if (args != NULL)
		status = ft_exit_aux(args);
	else
		status = 0;
	shell = *get_minishell(NULL);
	rl_clear_history();
	free_minishell(&shell);
	get_status(status);
	exit (status);
}

static int	ft_exit_aux(char *args)
{
	int	i;

	i = 0;
	if (ft_atoi(args) >= '0' && ft_atoi(args) <= '255')
		return (ft_atoi(args));
	while (args[i])
	{
		if (ft_isalpha(args[i]) == 0)
		{
			ft_printf_fd(STDERR_FILENO,
				"bash: exit: %s: numeric argument required\n", args);
			return (2);
		}
		i++;
	}
	return (1);
}
