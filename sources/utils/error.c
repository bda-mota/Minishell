#include "../../includes/minishell.h"

void	display_error_tokens(char *error, char c)
{
	if (ft_strcmp(error, "sintaxe") == 0)
		ft_printf_fd(STDERR_FILENO,
			"babyshell: syntax error near unexpected token `%c´\n", c);
	if (ft_strcmp(error, "newline") == 0)
		ft_printf_fd(STDERR_FILENO,
			"babyshell: syntax error near unexpected token `newline´\n", c);
	if (ft_strcmp(error, "||") == 0 || ft_strcmp(error, "&&") == 0)
		ft_printf_fd(STDERR_FILENO, WARNING_OR, 2);
	get_status(2);
}
