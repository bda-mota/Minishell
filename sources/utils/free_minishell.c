#include "../../includes/minishell.h"

void	free_minishell(t_minishell *shell)
{
	char	**env_copy;
	int		i;

	env_copy = *get_copy(NULL);
	i = 0;
	if (shell->paths)
		ft_free_matrix(shell->paths);
	if (shell->exec && shell->complete_path)
		free(shell->complete_path);
	if (shell->exec)
		free(shell->exec);
	if (shell->input)
		free(shell->input);
	if (env_copy)
		ft_free_matrix(env_copy);
	if (shell->tree)
		down_tree(&shell->tree);
}
