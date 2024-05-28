#include "../../includes/minishell.h"

void	env(char **env_copy)
{
	int	i;

	i = 0;
	while (env_copy[i])
	{
		ft_printf_fd("%s\n", env_copy[i], 1);
		i++;
	}
}
