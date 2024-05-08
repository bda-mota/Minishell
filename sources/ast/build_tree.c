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

t_tree	*search_delimiter(t_token **tokens, int delimiter)
{
	t_token	*curr;

	curr = get_last_node(*tokens);
	while (curr)
	{
		if (curr->type == delimiter)
			return (curr);
		curr = curr->prev;
	}
	return (NULL);
}

t_tree	*build_tree(t_token **tokens, t_tree **root)
{
	t_tree	*new;

	// percorrendo e se for search -> PIPE bloom_tree

	new = search_delimiter(create_root(*tokens), PIPE);
	bloom_tree(*root, new, RIGHT);
}

// lembrar de n mandar a raíz da árvore , mas sim o nó onde queremos adicionar à direita ou à esquerda

void	bloom_tree(t_tree **root, t_tree *new_branch, int side)
{
	t_tree	*curr;

	curr = *root;
	if (*root == NULL)
		*root = new_branch;
	else if (side == LEFT)
	{
		while (curr->left != NULL)
			curr = curr->left;
		curr->left = new_branch;
	}
	else if (side == RIGHT)
	{
		while (curr->right != NULL)
			curr = curr->right;
		curr->right = new_branch;
	}
}
