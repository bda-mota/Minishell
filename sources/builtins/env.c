#include "../../includes/minishell.h"

void	env(t_exec *env)
{
	int	i;

	i = 0;
	while (env->env_copy[i])
	{
		ft_printf_fd("%s\n", env->env_copy[i], 1);
		i++;
	}
}
