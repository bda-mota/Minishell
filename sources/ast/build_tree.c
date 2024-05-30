#include "../../includes/minishell.h"

void	build_tree(t_tree **root, t_token **tokens, int side)
{
	t_token	**lists;

	*lists = search_branch(tokens);
}
// void	build_tree(t_tree **root, t_token **tokens, int side)
// {
// 	t_token	*new_node;
// 	t_token	*left;
// 	t_token	*right;
// 	t_tree	*new_branch;

// 	new_node = search_branch(tokens);
// 	if (new_node == NULL)
// 		new_node = put_all_together(tokens);
// 	new_branch = create_root(new_node);
// 	bloom_tree(root, new_branch, side);
// 	left = new_node->prev;
// 	if (left != NULL)
// 	{
// 		left->next = NULL;
// 		build_tree(&new_branch, &left, LEFT);
// 	}
// 	right = new_node->next;
// 	if (right != NULL)
// 	{
// 		right->prev = NULL;
// 		build_tree(&new_branch, &right, RIGHT);
// 	}
// 	free(new_node->content);
// 	free(new_node);
// }

void	bloom_tree(t_tree **root, t_tree *new_branch, int side)
{
	t_tree	*parent;

	parent = *root;
	if (*root == NULL)
		*root = new_branch;
	else if (side == LEFT)
	{
		while (parent->left != NULL)
			parent = parent->left;
		parent->left = new_branch;
	}
	else
	{
		while (parent->right != NULL)
			parent = parent->right;
		parent->right = new_branch;
	}
	return ;
}
