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
	char	**new_environ;
	int		i;

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

int	update_variable(char **env_copy, char *var_name, char *new_var, int var_len)
{
	int	i;

	i = 0;
	while (env_copy[i])
	{
		if (ft_strncmp(env_copy[i], var_name, var_len) == 0
			&& env_copy[i][var_len] == '=')
		{
			free(env_copy[i]);
			env_copy[i] = ft_strdup(new_var);
			return (1);
		}
		i++;
	}
	return (0);
}

void	add_new_variable(char **env_copy, char *new_var)
{
	char	**new_environ;
	int		num_vars;

	new_environ = NULL;
	num_vars = 0;
	while (env_copy[num_vars])
		num_vars++;
	new_environ = create_new_environ(env_copy, num_vars);
	new_environ[num_vars] = ft_strdup(new_var);
	if (!new_environ[num_vars])
	{
		free(new_environ);
		return ;
	}
	free(*get_copy(NULL));
	*get_copy(NULL) = new_environ;
}

void	add_variable_to_environ(char **env_copy, char *new_var)
{
	char	*var_name;
	int		var_len;
	int		i;
	int		update;

	i = 0;
	update = 0;
	var_len = ft_strcspn(new_var, "=");
	var_name = ft_strndup(new_var, var_len);
	update = update_variable(env_copy, var_name, new_var, var_len);
	if (!update)
		add_new_variable(env_copy, new_var);
	free(var_name);
}
