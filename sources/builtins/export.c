#include "../../includes/minishell.h"

void	export(char **env_copy, char *new_variable)
{
	int	i;

	i = 0;
	if (new_variable)
		add_variable_to_environ(env_copy, new_variable);
	else
	{
		order_env(env_copy);
		while (env_copy[i])
		{
			printf("declare -x %s\n", env_copy[i]);
			i++;
		}
	}
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
