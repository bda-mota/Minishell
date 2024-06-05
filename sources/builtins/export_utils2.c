#include "../../includes/minishell.h"

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

size_t	ft_strlen_without_quotes(const char *str)
{
	size_t	len;
	int		simple_quote;
	int		double_quote;

	len = 0;
	simple_quote = 0;
	double_quote = 0;
	while (*str)
	{
		if (quotes(*str, &simple_quote, &double_quote))
		{
			str++;
			continue ;
		}
		len++;
		str++;
	}
	return (len);
}

char	*copy_var(char *new_var, int size)
{
	char	*var;
	int		i;
	int		j;
	int		simple_quote;
	int		double_quote;

	i = 0;
	j = 0;
	simple_quote = 0;
	double_quote = 0;
	var = ft_calloc(size + 1, sizeof(char));
	if (!var)
		return (NULL);
	while (new_var[i])
	{
		if (quotes(new_var[i], &simple_quote, &double_quote)
			|| new_var[i] == 32)
		{
			i++;
			continue ;
		}
		var[j++] = new_var[i++];
	}
	return (var);
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
	free(*get_copy(NULL));
	*get_copy(NULL) = new_environ;
}

void	variable_to_environ(char **env_copy, char *new_var)
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
	{
		if (!check_variable_name(var_name))
			add_new_variable(env_copy, new_var);
	}
	free(var_name);
}

int	check_variable_name(char *var_name)
{
	int	i;

	i = 0;
	if (var_name[i] != '_' && !ft_isalpha(var_name[i]))
	{
		ft_printf_fd("export: '%s': not a valid identifier\n", var_name, 2);
		return (1);
	}
	while (var_name[i])
	{
		if (!ft_isalnum(var_name[i]) && var_name[i] != '_')
		{
			ft_printf_fd("export: `%s': not a valid identifier\n", var_name, 2);
			return (1);
		}
		i++;
	}
	return (0);
}
