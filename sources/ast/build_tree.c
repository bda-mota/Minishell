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
		if (curr->type == APPEND || curr->type == HEREDOC
			|| curr->type == INPUT || curr->type == OUTPUT)
			return (curr);
		curr = curr->prev;
	}
	return (*tokens);
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
	new_branch = create_root(new_node);
	bloom_tree(root, new_branch, side);

	right = new_node->next;
	if (right != NULL)
		right->prev = NULL;
	left = new_node->prev;
	if (left != NULL)
		left->next = NULL;
	//free(new_node->content);
	//free(new_node);
	if (left == NULL)
		return ;
	build_tree(&new_branch, &left, LEFT);
	if (right == NULL)
		return ;
	build_tree(&new_branch, &right, RIGHT);
}
