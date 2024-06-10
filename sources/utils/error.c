#include "../../includes/minishell.h"

void	display_error_tokens(char *error, char c)
{
	if (ft_strcmp(error, "sintaxe") == 0)
		ft_printf_fd("syntax error near unexpected token `%c´\n", c, 2);
	if (ft_strcmp(error, "||") == 0 || ft_strcmp(error, "&&") == 0)
		ft_printf_fd(WARNING_OR, 2);
}

int	display_error_exec(char *error, char *str)
{
	if (ft_strcmp(error, "permission denied") == 0)
		return (get_status(1));
	else if (ft_strcmp(error, "is a directory") == 0)
		ft_printf_fd("Babyshell: %s: Is a directory\n", str, 2);
	else if (ft_strcmp(error, "no_file") == 0)
	{
		ft_printf_fd("Babyshell: %s: No such file or directory.\n", str, 2);
		return (get_status(1));
	}
	else if (ft_strcmp(error, "command not found") == 0)
	{
		ft_printf_fd("Babyshell: command not found: `%s´\n", str, 2);
		return (get_status(127));
	}
	return (1);
}
