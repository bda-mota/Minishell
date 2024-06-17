#include "../../includes/minishell.h"

void	ft_export(char **env_copy, char *new_variable)
{
	if (new_variable == NULL)
		print_variables(env_copy);
	else
		change_variables(new_variable);
}

void	print_variables(char	**env_copy)
{
	int		i;
	char	*signal;

	i = 0;
	order_env(env_copy);
	while (env_copy[i])
	{
		signal = ft_strchr(env_copy[i], '=');
		if (signal)
		{
			printf("declare -x %.*s", (int)(signal - env_copy[i]), env_copy[i]);
			printf("=\"%s\"\n", signal + 1);
		}
		else
			printf("declare -x %s\n", env_copy[i]);
		i++;
	}
}

void	order_env(char **env_copy)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (env_copy[i])
	{
		j = i + 1;
		while (env_copy[j])
		{
			if (ft_strncmp(env_copy[i],
					env_copy[j], ft_strlen(env_copy[i])) > 0)
			{
				tmp = env_copy[i];
				env_copy[i] = env_copy[j];
				env_copy[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	change_variables(char *new_variable)
{
	t_var	state;

	state.args = 0;
	state.start = 0;
	state.simple_quote = 0;
	state.double_quote = 0;
	while (new_variable[state.args])
	{
		state.environ = *get_env_copy(NULL);
		state.start = state.args;
		while (new_variable[state.args]
			&& (new_variable[state.args] != ' '
				|| state.simple_quote || state.double_quote))
		{
			quotes(new_variable[state.args],
				&(state.simple_quote), &(state.double_quote));
			(state.args)++;
		}
		if (state.start != state.args)
			processed_var(state.environ, new_variable, state.start, state.args);
		if (new_variable[state.args] != '\0')
			(state.args)++;
	}
}

void	processed_var(char **environ, char *new_variable, int start, int args)
{
	char	*var;

	var = ft_strndup(&new_variable[start], args - start);
	if (var)
	{
		variable_to_environ(environ, var);
		free (var);
	}
}
