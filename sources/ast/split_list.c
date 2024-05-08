#include "../../includes/minishell.h"

t_token	*find_delimiter(t_token *tokens, int delimiter)
{
	t_token	*curr;

	curr = tokens;
	while (curr && curr != delimiter)
		curr = curr->next;
	return (curr);
}

t_token	*find_prev(t_token *tokens, int delimiter)
{
	t_token	*curr;
	t_token	*prev;

	curr = tokens;
	prev = NULL;
	while (curr && curr != delimiter)
	{
		prev = curr;
		curr = curr->next;
	}
	return (prev);
}

t_tree	*split_list(t_token **tokens, int delimiter) // tokens vai ser enviada de trás para frente
{
	t_token	*curr;
	t_token	*prev;
	t_token	*left;
	t_token	*right;
	t_tree	*new;

	prev = find_prev(tokens, delimiter);
	curr = find_delimiter(tokens, delimiter);
	if (!curr || !prev)
		return (NULL);
	prev->next = NULL;
	curr->prev = NULL;
	left = curr->next;
	right = *tokens;
	new = malloc(sizeof(t_tree));
	if (!new)
		return (NULL);
	new->type = curr->type;
	new->content = strdup(curr->content);
	new->left = build_tree(&left);
	new->right = build_tree(&right);
	*tokens = right;
	return (new);
}
