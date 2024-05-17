#include "../../includes/minishell.h"

t_token	*search_delimiter(t_token **tokens)
{
	t_token	*curr;

	curr = get_last_node(tokens);
	while (curr)
	{
		if (curr->type == PIPE)
			return (curr);
		curr = curr->prev;
	}
	curr = get_last_node(tokens);
	while (curr)
	{
		if (is_metha(curr))
			return (curr);
		curr = curr->prev;
	}
	return (NULL);
}

t_tree	*create_root(t_token *tokens)
{
	t_tree	*new_root;

	new_root = ft_calloc(sizeof(t_tree), 1);
	if (!new_root)
		return (NULL);
	new_root->type = tokens->type;
	new_root->content = ft_strdup(tokens->content);
	return (new_root);
}

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

void	build_tree(t_tree **root, t_token **tokens, int side)
{
	t_token	*new_node;
	t_token	*left;
	t_token	*right;
	t_tree	*new_branch;

	new_node = search_delimiter(tokens);
	if (new_node == NULL)
		new_node = put_all_together(tokens);
	new_branch = create_root(new_node);
	bloom_tree(root, new_branch, side);
	left = new_node->prev;
	if (left != NULL)
	{
		left->next = NULL;
		build_tree(&new_branch, &left, LEFT);
	}
	right = new_node->next;
	if (right != NULL)
	{
		right->prev = NULL;
		build_tree(&new_branch, &right, RIGHT);
	}
	free(new_node->content);
	free(new_node);
}
