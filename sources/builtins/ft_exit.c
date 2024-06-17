#include "../../includes/minishell.h"

static int	ft_exit_aux(char *args);
static int	calc_exit(int number);

int	ft_exit(char *args)
{
	t_minishell	shell;
	int			status;

	if (args != NULL)
		status = ft_exit_aux(args);
	else
		status = 0;
	if (status == 1)
		return (1);
	shell = *get_minishell(NULL);
	rl_clear_history();
	free_minishell(&shell);
	get_status(status);
	exit (status);
}

static int	ft_exit_aux(char *args)
{
	int	i;
	int	number;

	i = 0;
	number = ft_atoi(args);
	while (args[i])
	{
		if (ft_isalpha(args[i]) == 1)
		{
			ft_printf_fd(STDERR_FILENO,
				"babyshell: exit: %s: numeric argument required\n", args);
			return (2);
		}
		if (ft_isspace(args[i]) == 1)
		{
			ft_printf_fd(STDERR_FILENO, "babyshell: exit: too many arguments\n");
			return (1);
		}
		i++;
	}
	if (number > 0 && number < 255)
		return (ft_atoi(args));
	else if (number < 0 || number > 255)
		return (calc_exit(number));
	return (0);
}

static int	calc_exit(int number)
{
	int	result;

	result = number % 256;
	if (number < 0)
		result += 256;
	return (result);
}
