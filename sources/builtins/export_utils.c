#include "../../includes/minishell.h"

// caso não crie a variável por erro de sintaxe tem que ajustar a saída de erro;

void	variable_to_environ(char **env_copy, char *new_var)
{
	char	*var_name;
	int		var_len;
	int		update;

	update = 0;
	var_len = ft_strcspn(new_var, "=");
	var_name = ft_strndup(new_var, var_len);
	update = update_variable(env_copy, var_name, new_var, var_len);
	if (!update)
	{
		if (!check_variable_name(var_name))
			add_new_variable(env_copy, new_var);
	}
	free(var_name);
}

int	update_variable(char **env_copy, char *var_name, char *new_var, int var_len)
{
	int		i;
	char	*new_env;

	i = 0;
	while (env_copy[i])
	{
		if (ft_strncmp(env_copy[i], var_name, var_len) == 0
			&& (env_copy[i][var_len] == '=' || env_copy[i][var_len] == '\0'))
		{
			new_env = build_var(env_copy[i], new_var, var_len);
			if (!new_env)
				return (0);
			free(env_copy[i]);
			env_copy[i] = new_env;
			return (1);
		}
			i++;
	}
	return (0);
}

char	*build_var(char *env_copy, char *new_var, int var_len)
{
	char	*new_value_start;
	char	*new_env;
	int		size_var;

	new_value_start = ft_strchr(env_copy, '=');
	if (new_value_start)
	{
		new_value_start++;
		size_var = var_len + 1
			+ ft_strlen_without_quotes(new_var + var_len + 1) + 1;
		new_env = ft_calloc(size_var, 1);
		if (!new_env)
			return (NULL);
		ft_strncpy(new_env, env_copy, var_len + 1);
		ft_strcpy_without_quotes(new_env + var_len + 1, new_var + var_len + 1);
	}
	else
	{
		size_var = ft_strlen(new_var) + 1;
		new_env = ft_calloc(size_var, 1);
		if (!new_env)
			return (NULL);
		ft_strcpy(new_env, new_var);
	}
	return (new_env);
}

void	add_new_variable(char **env_copy, char *new_var)
{
	char	**new_environ;
	int		num_vars;
	int		size;

	new_environ = NULL;
	num_vars = 0;
	size = ft_strlen_without_quotes(new_var);
	while (env_copy[num_vars])
		num_vars++;
	new_environ = create_new_environ(env_copy, num_vars);
	new_environ[num_vars] = copy_var(new_var, size);
	if (!new_environ[num_vars])
	{
		free(new_environ);
		return ;
	}
	free(*get_env_copy(NULL));
	*get_env_copy(NULL) = new_environ;
}

int	check_variable_name(char *var_name)
{
	int	i;

	i = 0;
	if (var_name[i] != '_' && !ft_isalpha(var_name[i]))
	{
		ft_printf_fd(STDERR_FILENO,
			"export: `%s': not a valid identifier\n", var_name);
		get_status(1);
		return (1);
	}
	while (var_name[i])
	{
		if (!ft_isalnum(var_name[i]) && var_name[i] != '_')
		{
			ft_printf_fd(STDERR_FILENO,
				"export: `%s': not a valid identifier\n", var_name);
			get_status(1);
			return (1);
		}
		i++;
	}
	get_status(0);
	return (0);
}
