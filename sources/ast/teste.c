#include "../../includes/minishell.h"

t_tree	*create_root(t_token *tokens)
{
	t_tree	*new_root;

	new_root = malloc(sizeof(t_tree));
	if (!new_root)
		return (NULL);
	new_root->type = tokens->type;
	new_root->content = ft_strdup(tokens->content);
	new_root->left = NULL;
	new_root->right = NULL;
	return (new_root);
}

//precisa sempre retornar root para não perder a referência dela
t_tree	*bloom_tree(t_tree **root, t_tree *new_branch, int side)
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
	return (*root);
}