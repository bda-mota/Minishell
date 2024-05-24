#include "../../includes/minishell.h"

void	free_minishell(t_minishell *shell)
{
	int	i;

	i = 0;
	if (shell->exec && shell->exec->paths)
	{
		while (shell->exec->paths[i])
		{
			free(shell->exec->paths[i]);
			i++;
		}
	}
	if (shell->exec && shell->exec->complete_path)
		free(shell->exec->complete_path);
	if (shell->exec && shell->exec->command_child)
		free(shell->exec->command_child);
	if (shell->exec)
		free(shell->exec);
	if (shell->input)
		free(shell->input);
	if (shell->env_copy)
		ft_free_matrix(shell->env_copy);
	if (shell->tree)
		down_tree(&shell->tree);
}
