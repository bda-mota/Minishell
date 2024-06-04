#include "../../includes/minishell.h"

void	change_variables(char *new_variable)
{
	int		args;
	int		start;
	char	*var;
	char	**environ;

	args = 0;
	start = 0;
	environ = NULL;
	while (new_variable[args])
	{
		environ = *get_copy(NULL);
		start = args;
		while (new_variable[args] && new_variable[args] != 32)
			args++;
		if (start != args)
		{
			var = ft_strndup(&new_variable[start], args - start);
			if (var)
			{
				variable_to_environ(environ, var);
				free (var);
			}
		}
		args++;
	}
}

// rever ordenação de lista de variáveis, está com erro
void	print_variables(char	**env_copy)
{
	int	i;

	i = 0;
	order_env(env_copy);
	while (env_copy[i])
	{
		printf("declare -x %s\n", env_copy[i]);
		i++;
	}
}


void	ft_export(char **env_copy, char *new_variable)
{
	if (new_variable)
		change_variables(new_variable);
	else
		print_variables(env_copy);
}

void	swap_strings(char **str1, char **str2)
{
	char	*tmp;

	tmp = *str1;
	*str1 = *str2;
	*str2 = tmp;
}

void	order_env(char **env_copy)
{
	int	i;
	int	j;
	int	min_index;

	i = 0;
	j = i + 1;
	min_index = 0;
	while (env_copy[i])
	{
		while (env_copy[j])
		{
			if (ft_strcmp(env_copy[j], env_copy[min_index]) < 0)
			{
				min_index = j;
			}
			j++;
		}
		if (min_index != i)
			swap_strings(&env_copy[i], &env_copy[min_index]);
		i++;
	}
}
