#include "../../includes/minishell.h"

void	display_error_tokens(char *error, char c)
{
	if (ft_strcmp(error, "sintaxe") == 0)
		ft_printf_fd(STDERR_FILENO,
			"syntax error near unexpected token `%c´\n", c);
	if (ft_strcmp(error, "newline") == 0)
		ft_printf_fd(STDERR_FILENO,
			"syntax error near unexpected token `newline´\n", c);
	if (ft_strcmp(error, "||") == 0 || ft_strcmp(error, "&&") == 0)
		ft_printf_fd(STDERR_FILENO, WARNING_OR, 2);
	get_status(2);
}

int	display_error_exec(char *error, char *str)
{
	if (ft_strcmp(error, "permission denied") == 0)
		return (get_status(1));
	else if (ft_strcmp(error, "is a directory") == 0)
		ft_printf_fd(STDERR_FILENO, "Babyshell: %s: Is a directory\n", str);
	else if (ft_strcmp(error, "no_file") == 0)
	{
		ft_printf_fd(STDERR_FILENO,
			"Babyshell: %s: No such file or directory.\n", str);
		return (get_status(1));
	}
	else if (ft_strcmp(error, "command not found") == 0)
	{
		ft_printf_fd(STDERR_FILENO, "Babyshell: command not found: `%s´\n", str);
		return (get_status(127));
	}
	return (1);
}
