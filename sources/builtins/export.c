#include "../../includes/minishell.h"

void	export(char **env_copy, char *new_variable)
{
	int	i;

	i = 0;
	if (new_variable)
		add_variable_to_environ(env_copy, new_variable);
	else
	{
		order_env(env_copy);
		while (env_copy[i])
		{
			printf("declare -x %s\n", env_copy[i]);
			i++;
		}
	}
}
