#include "../../includes/minishell.h"

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
