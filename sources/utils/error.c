#include "../../includes/minishell.h"

void	display_error(char *error, char c)
{
	if (ft_strcmp(error, "sintaxe") == 0)
		ft_printf_fd("syntax error near unexpected token `%c´\n", c, 2);
	if (ft_strcmp(error, "||") == 0 || ft_strcmp(error, "&&") == 0)
		ft_printf_fd(WARNING_OR, 2);
}
