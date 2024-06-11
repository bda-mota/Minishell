#include "../../includes/minishell.h"

void	free_minishell(t_minishell *shell)
{
	char	**env_copy;

	env_copy = *get_env_copy(NULL);
	if (shell->input)
		free(shell->input);
	if (env_copy)
		ft_free_matrix(env_copy);
	if (shell->tree)
		down_tree(&shell->tree);
	close_all();
}
