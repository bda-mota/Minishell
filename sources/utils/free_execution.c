#include "../../includes/minishell.h"

void	free_execution(t_tree *tree, char *input)
{
	if (input)
		free (input);
	if (tree && tree->command_child)
		ft_free_matrix(tree->command_child);
	if (tree && tree->path_cmd)
		ft_free_matrix(tree->path_cmd);
	if (tree)
		free(tree);
}
