#include "../../includes/minishell.h"

void	unset(t_minishell *shell, char *remove_var)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = strlen(remove_var);
	while (shell->env_copy[i])
	{
		if (strncmp(shell->env_copy[i], remove_var, len) == 0
			&& shell->env_copy[i][len] == '=')
		{
			free(shell->env_copy[i]);
			j = i;
			while (shell->env_copy[j])
			{
				shell->env_copy[j] = shell->env_copy[j + 1];
				j++;
			}
		}
		i++;
	}
}
