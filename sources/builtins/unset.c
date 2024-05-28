#include "../../includes/minishell.h"

void	unset(char **env_copy, char *remove_var)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(remove_var);
	while (env_copy[i])
	{
		if (ft_strncmp(env_copy[i], remove_var, len) == 0
			&& env_copy[i][len] == '=')
		{
			free(env_copy[i]);
			j = i;
			while (env_copy[j])
			{
				env_copy[j] = env_copy[j + 1];
				j++;
			}
		}
		i++;
	}
}
