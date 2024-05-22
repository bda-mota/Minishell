#include "../../includes/minishell.h"

void	env(char **environ_copy)
{
	int	i;

	i = 0;
	while (environ_copy[i])
	{
		ft_printf_fd("%s\n", environ_copy[i], 1);
		i++;
	}
}
