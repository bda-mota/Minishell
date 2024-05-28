#include "../../includes/minishell.h"

void	free_execution(void)
{
	t_minishell	*shell;

	shell = get_minishell(NULL);
	if (shell->input)
		free (shell->input);
	//if (shell->tree && shell->tree->command_child)
	//	ft_free_matrix(shell->tree->command_child);
	//if (shell->tree && shell->tree->executable)
	//	free(shell->tree->executable);
	if (shell->tree)
		down_tree(&shell->tree);
}
