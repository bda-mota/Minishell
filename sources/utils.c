#include "../includes/minishell.h"

void	display_error(char *error, char c)
{
	if (ft_strcmp(error, "sintaxe") == 0)
	{
		ft_putstr_fd(WARNING_SINTAXE, 2);
		write(2, &c, 1);
		write(2, "\n", 1);
	}
	if (ft_strcmp(error, "||") == 0 || ft_strcmp(error, "&&") == 0)
		ft_putstr_fd(WARNING_OR, 2);
}
