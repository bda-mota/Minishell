#include "../../includes/minishell.h"

static int	ft_exit_aux(char *args);
static int	calc_exit(int number);
static char	*remove_quotes(char *args);
static int	contains_syntax_error(char *new);

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
	int		type;
	int		number;
	char	*new;

	i = 0;
	new = remove_quotes(args);
	number = ft_atoi(new);
	type = contains_syntax_error(new);
	if (type == 1)
		return (1);
	else if (type == 2)
		return (2);
	if (number >= 0 && number <= 255)
	{
		free(new);
		return (number);
	}
	else
	{
		free(new);
		return (calc_exit(number));
	}
}

static int	contains_syntax_error(char *new)
{
	int	i;

	i = 0;
	while (new[i])
	{
		if (ft_isalpha(new[i]) == 1)
		{
			ft_printf_fd(STDIN_FILENO, "exit\n");
			ft_printf_fd(STDERR_FILENO,
				"babyshell: exit: %s: numeric argument required\n", new);
			free(new);
			return (2);
		}
		if (ft_isspace(new[i]) == 1)
		{
			ft_printf_fd(STDIN_FILENO, "exit\n");
			ft_printf_fd(STDERR_FILENO, "babyshell: exit: too many arguments\n");
			free(new);
			return (1);
		}
		i++;
	}
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

static char	*remove_quotes(char *args)
{
	int		i;
	int		j;
	int		len;
	char	*new_args;

	i = 0;
	j = 0;
	len = ft_strlen(args);
	new_args = ft_calloc(sizeof(char), len + 1);
	if (!new_args)
		return (NULL);
	while (args[i])
	{
		if (args[i] != '\'' && args[i] != '\"')
		{
			new_args[j] = args[i];
			j++;
		}
		i++;
	}
	return (new_args);
}
