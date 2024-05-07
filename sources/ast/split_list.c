#include "../../includes/minishell.h"

t_tree	*split_list(t_token **tokens, int delimiter)
{
	t_token	*curr;
	t_token	*prev;
	t_tree	*new;

	curr = *tokens;
	while (curr && curr->type != delimiter)
	{
		prev = curr;
		curr = curr->next;
	}
	if (!curr || !prev)
		return (NULL);
	prev->next = NULL;
	curr->prev = NULL;
	new = malloc(sizeof(t_tree));
	if (!new)
		return ;

}
