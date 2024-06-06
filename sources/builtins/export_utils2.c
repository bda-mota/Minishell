#include "../../includes/minishell.h"

int	ft_strlen_without_quotes(const char *str)
{
	int		len;
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

int	check_variable_name(char *var_name)
{
	int	i;

	i = 0;
	if (var_name[i] != '_' && !ft_isalpha(var_name[i]))
	{
		ft_printf_fd("export: `%s': not a valid identifier\n", var_name, 2);
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
	return (*get_env_copy(environ_copy));
}

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
