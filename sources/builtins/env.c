#include "../../includes/minishell.h"

void	env(t_exec *env)
{
	char	**env_original;
	int		i;

	env_original = __environ;
	i = 0;
	if (!env->env_copy)
	{
		while (env_original[i])
		{
			ft_printf_fd("%s\n", env_original[i], 1);
			i++;
		}
	}
	else
	{
		i = 0;
		while (env->env_copy[i])
		{
			ft_printf_fd("%s\n", env->env_copy[i], 1);
			i++;
		}
	}
}
