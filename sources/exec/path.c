#include "../../includes/minishell.h"

extern char	**environ;

void	find_path(t_exec **execution)
{
	int		i;
	char	**env;

	i = 0;
	env = environ;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			(*execution)->complete_path = (env[i] + 5);
		i++;
	}
	(*execution)->env = environ;
	printf("PATH: %s\n", (*execution)->complete_path);
	build_path(execution);
}

void	build_path(t_exec **execution)
{
	int		i;
	char	*aux;

	i = 0;
	(*execution)->paths = ft_split((*execution)->complete_path, ':');
	if ((*execution)->paths == NULL)
		printf("error\n");
	while ((*execution)->paths[i])
	{
		aux = ft_strdup((*execution)->paths[i]);
		if (aux == NULL)
			break ;
		free((*execution)->paths[i]);
		(*execution)->paths[i] = ft_strjoin(aux, "/");
		free(aux);
		i++;
	}
	i = 0;
	while ((*execution)->paths[i])
	{
		printf("PATH[%d]: %s\n", i, (*execution)->paths[i]);
		i++;
	}
}

char	*add_command_to_path(t_exec **execution, char *cmd)
{
	int		i;
	char	*aux_cmd;
	char	**take_first;

	i = 0;
	take_first = ft_split(cmd, ' ');
	if (take_first == NULL)
		printf("error\n");
	while ((*execution)->paths[i])
	{
		aux_cmd = ft_strjoin((*execution)->paths[i], take_first[0]);
		if (access(aux_cmd, X_OK) == 0)
		{
			ft_free_matrix(take_first);
			return (aux_cmd);
		}
		free(aux_cmd);
		i++;
	}
	ft_free_matrix(take_first);
	return (NULL);
}
