#include "../../includes/minishell.h"

void	free_child(void)
{
	t_tree	*tree;

	tree = get_tree(NULL);
	tree = NULL;
	if (tree && tree->command)
		free(tree->command);
	if (tree && tree->command_child)
		ft_free_matrix(tree->command_child);
	if (tree)
		down_tree(&tree);
}
