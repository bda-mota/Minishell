#include "../../includes/minishell.h"

static void	copy_variable(char *var, char *line, int *pos);

char	*expand_heredoc(char *line, int *pos)
{
	int		i;
	int		j;
	char	**env_copy;
	char	*var;

	i = 0;
	var = ft_calloc(sizeof(char), ft_strlen(line) + 1);
	if (!var)
		return (NULL);
	env_copy = *get_env_copy(NULL);
	copy_variable(var, line, pos);
	j = ft_strlen(var);
	while (env_copy[i])
	{
		if (ft_strncmp(env_copy[i], var, j) == 0 && env_copy[i][j] == '=')
		{
			free(var);
			return (env_copy[i] + j + 1);
		}
		i++;
	}
	free(var);
	return (NULL);
}

static void	copy_variable(char *var, char *line, int *pos)
{
	int	j;

	j = 0;
	while (line[*pos] && line[*pos] != ' '
		&& line[*pos] != '\'' && line[*pos] != '"')
	{
		var[j] = line[*pos];
		j++;
		(*pos)++;
	}
}
