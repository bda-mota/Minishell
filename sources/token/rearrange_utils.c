#include "../../includes/minishell.h"

int	check_pipeline(t_token **tokens)
{
	t_token	*curr;

	curr = *tokens;
	while (curr)
	{
		if (is_redir_or_heredoc(&curr))
		{
			while (curr && curr->type != PIPE)
			{
				if (!is_redir_or_heredoc(&curr) && curr->type != ARCHIVE)
					return (1);
				curr = curr->next;
			}
			return (0);
		}
		if (curr->next)
			curr = curr->next;
	}
	return (0);
}

t_token	*get_last_node_of_pipeline(t_token **tokens)
{
	t_token	*last_node;

	last_node = *tokens;
	if (*tokens == NULL)
		return (NULL);
	while (last_node->next != NULL && last_node->next->type != PIPE)
		last_node = last_node->next;
	return (last_node);
}

t_token	*get_first_node_of_pipeline(t_token **tokens)
{
	t_token	*first_node;

	first_node = *tokens;
	if (*tokens == NULL)
		return (NULL);
	while (first_node->prev != NULL && first_node->prev->type != PIPE)
		first_node = first_node->prev;
	return (first_node);
}

t_token	*get_first_word(t_token **tokens)
{
	t_token	*first;

	first = *tokens;
	if (is_redir_or_heredoc(&first))
		return (NULL);
	while (first && !is_redir_or_heredoc(&first->next))
		first = first->next;
	return (first);
}
