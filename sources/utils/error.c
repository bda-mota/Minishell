#include "../../includes/minishell.h"

void	display_error_tokens(char *error, char c)
{
	if (ft_strcmp(error, "sintaxe") == 0)
		ft_printf_fd("syntax error near unexpected token `%c´\n", c, 2);
	if (ft_strcmp(error, "||") == 0 || ft_strcmp(error, "&&") == 0)
		ft_printf_fd(WARNING_OR, 2);
}

void	display_error_exec(char *error, char *str)
{
	if (ft_strcmp(error, "permission denied") == 0)
		ft_printf_fd("Babyshell: %s: %s: Permission denied\n", str, 2);
	if (ft_strcmp(error, "is a directory") == 0)
		ft_printf_fd("Babyshell: %s: %s: Is a directory\n", str, 2);
	if (ft_strcmp(error, "no such file or directory") == 0)
		ft_printf_fd("Babyshell: %s: %s: No such file or directory\n", str, 2);
	if (ft_strcmp(error, "command not found") == 0)
		ft_printf_fd("Babyshell: command not found: `%s´\n", str, 2);
}
