#include "../../includes/minishell.h"

static int	ft_exit_aux(char *args);
static int	calc_exit(int number);
static int	check_quotes_exit(char *args);
static char	*remove_quotes(char *args);

int	ft_exit(char *args)
{
	t_minishell	shell;
	int			status;

	if (args != NULL)
		status = ft_exit_aux(args);
	else
		status = 0;
	if (status == 1)
		return (get_status(status));
	shell = *get_minishell(NULL);
	rl_clear_history();
	free_minishell(&shell);
	get_status(status);
	exit (status);
}

static int	ft_exit_aux(char *args)
{
	int		i;
	char	*new;
	int		number;

	i = 0;
	new = remove_quotes(args);
	number = ft_atoi(new);
	while (new[i])
	{
		if (ft_isalpha(new[i]) == 1)
		{
			ft_printf_fd(STDERR_FILENO,
				"babyshell: exit: %s: numeric argument required\n", new);
			return (2);
		}
		if (ft_isspace(new[i]) == 1)
		{
			ft_printf_fd(STDIN_FILENO, "exit\n");
			ft_printf_fd(STDERR_FILENO, "babyshell: exit: too many arguments\n");
			return (1);
		}
		i++;
	}
	if (number > 0 && number < 255)
	{
		return (ft_atoi(new));
	}
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

static int	check_quotes_exit(char *args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (args[i] == '\'' || args[i] == '\"')
			return (1);
		i++;
	}
	return (0);
}

static char	*remove_quotes(char *args)
{
	int		i;
	int		j;
	int		len;
	char	*new_args;

	i = 0;
	j = 0;
	len = ft_strlen(args);
	if (check_quotes_exit(args) == 1)
	{
		new_args = ft_calloc(sizeof(char), len - 2);
		while (args[i])
		{
			while (args[i] && (args[i] == '\'' || args[i] == '\"'))
				i++;
			new_args[j] = args[i];
			j++;
			i++;
		}
		return (new_args);
	}
	else
		return (args);
}
