#include "../../includes/minishell.h"

void	unset(t_exec *env, char *remove_var)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = strlen(remove_var);
	while (env->env_copy[i])
	{
		if (strncmp(env->env_copy[i], remove_var, len) == 0
			&& env->env_copy[i][len] == '=')
		{
			free(env->env_copy[i]);
			j = i;
			while (env->env_copy[j])
			{
				env->env_copy[j] = env->env_copy[j + 1];
				j++;
			}
		}
		i++;
	}
}
