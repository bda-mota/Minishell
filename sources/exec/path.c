#include "../../includes/minishell.h"

void	find_path(t_minishell *shell)
{
	int		i;
	char	**env;

	i = 0;
	env = __environ;
	if (!shell->complete_path)
	{
		while (env[i])
		{
			if (ft_strncmp(env[i], "PATH=", 5) == 0)
			{
				shell->complete_path = (env[i] + 5);
				break ;
			}
			i++;
		}
	}
	if (!shell->paths)
		build_path(shell);
}

void	build_path(t_minishell *shell)
{
	int		i;
	char	*aux;

	i = 0;
	shell->paths = ft_split(shell->complete_path, ':');
	if (shell->paths == NULL)
		printf("error ao dar split\n");
	while (shell->paths[i])
	{
		aux = ft_strdup(shell->paths[i]);
		if (aux == NULL)
			break ;
		free(shell->paths[i]);
		shell->paths[i] = ft_strjoin(aux, "/");
		free(aux);
		i++;
	}
}

void	copy_path_to_exec(t_minishell *shell)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (shell->paths[len])
		len++;
	shell->exec->path_cmd = ft_calloc(len + 1, sizeof(char *));
	if (shell->exec->path_cmd == NULL)
		printf("error ao alocar path_cmd\n");
	while (shell->paths[i])
	{
		shell->exec->path_cmd[i] = ft_strdup(shell->paths[i]);
		if (shell->exec->path_cmd[i] == NULL)
			printf("error ao dar strdup\n");
		i++;
	}
	shell->exec->path_cmd[i] = NULL;
}
