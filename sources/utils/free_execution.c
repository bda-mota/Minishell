#include "../../includes/minishell.h"

void	free_execution(void)
{
	t_minishell	*shell;

	shell = get_minishell(NULL);
	if (shell->input)
		free (shell->input);
	if (shell->paths)
	{
		ft_free_matrix(shell->paths);
		shell->paths = NULL;
	}
	if (shell->tree)
		down_tree(&shell->tree);
}
