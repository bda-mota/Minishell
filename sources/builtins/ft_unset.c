#include "../../includes/minishell.h"

static void	aux_unset(char **env_copy, char *remove_var)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(remove_var);
	while (env_copy[i])
	{
		if (ft_strncmp(env_copy[i], remove_var, len) == 0)
		{
			free(env_copy[i]);
			j = i;
			while (env_copy[j])
			{
				env_copy[j] = env_copy[j + 1];
				j++;
			}
		}
		i++;
	}
}

void	ft_unset(char **env_copy, char *variables)
{
	char	*remove_var;
	int		start;
	int		end;
	int		len;

	start = 0;
	if (!variables)
		return ;
	len = ft_strlen(variables);
	while (start < len)
	{
		while (start < len && variables[start] == ' ')
			start++;
		end = start;
		while (end < len && variables[end] != ' ')
			end++;
		if (start < end)
		{
			remove_var = ft_calloc(end - start + 1, 1);
			ft_strncpy(remove_var, variables + start, end - start);
			if (check_variable_name(remove_var) == 0)
			{
				aux_unset(env_copy, remove_var);
				free(remove_var);
			}
			else
			{
				free(remove_var);
				get_status(1);
				return ;
			}
		}
		start = end + 1;
	}
	get_status(0);
}
