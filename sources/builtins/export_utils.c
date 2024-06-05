#include "../../includes/minishell.h"

char	**count_size_environ(void)
{
	char	**env;
	char	**environ_copy;
	int		num_vars;

	env = __environ;
	environ_copy = NULL;
	num_vars = 0;
	while (env[num_vars])
		num_vars++;
	environ_copy = ft_calloc(num_vars + 1, sizeof(char *));
	if (!environ_copy)
		return (NULL);
	return (environ_copy);
}

char	**copy_environ(void)
{
	char	**env;
	char	**environ_copy;
	int		i;

	env = __environ;
	environ_copy = count_size_environ();
	if (!environ_copy)
		return (NULL);
	i = 0;
	while (env[i])
	{
		environ_copy[i] = ft_strdup(env[i]);
		if (!environ_copy[i])
		{
			while (i--)
				free(environ_copy[i]);
			free(environ_copy);
			return (NULL);
		}
		i++;
	}
	return (*get_copy(environ_copy));
}

char	**create_new_environ(char **environ_copy, int num_vars)
{
	int		i;
	char	**new_environ;

	i = 0;
	new_environ = ft_calloc(num_vars + 2, sizeof(char *));
	if (!new_environ)
		return (NULL);
	while (i < num_vars)
	{
		new_environ[i] = environ_copy[i];
		i++;
	}
	return (new_environ);
}
