#include "../../includes/minishell.h"

void	down_tree(t_tree *root)
{
	if (root == NULL)
		return ;
	down_tree(root->left);
	down_tree(root->right);
	if (root->content)
		free(root->content);
	free(root);
}
