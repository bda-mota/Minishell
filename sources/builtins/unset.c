#include "../../includes/minishell.h"

char	**unset(char **environ_copy, char *remove_var)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = strlen(remove_var);
	while (environ_copy[i])
	{
		if (strncmp(environ_copy[i], remove_var, len) == 0
			&& environ_copy[i][len] == '=')
		{
			free(environ_copy[i]);
			j = i;
			while (environ_copy[j])
			{
				environ_copy[j] = environ_copy[j + 1];
				j++;
			}
		}
		i++;
	}
	return (environ_copy);
}
