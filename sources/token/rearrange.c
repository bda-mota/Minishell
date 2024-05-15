#include "../../includes/minishell.h"

static t_token	*rearrange_more_than_one(t_token **tokens);

void	rearrange_tokens(t_token **tokens)
{
	t_token	*curr;
	int		redir;

	curr = *tokens;
	while (curr)
	{
		if (curr->type == OUTPUT && curr->next)
		{
			redir = check_redirects_on_pipeline(&curr);
			while (check_pipeline(&curr) == 1)
			{
				curr = rearrange_more_than_one(&curr);
				curr = curr->next;
			}
		}
		curr = curr->next;
	}
}

static t_token	*rearrange_more_than_one(t_token **tokens)
{
	t_token	*word;
	t_token	*first;
	t_token	*new;
	t_token	*output;

	new = NULL;
	word = *tokens;
	output = get_first_node_of_pipeline(&word);
	first = (get_first_word(&output));
	while (output && output->type != OUTPUT)
		output = output->next;
	while (word)
	{
		if (word->type != OUTPUT && word->type != ARCHIVE)
		{
			new = split_list(&word);
			break ;
		}
		word = word->next;
	}
	new->prev = first;
	first->next = new;
	new->next = output;
	return (word);
}

t_token	*split_list(t_token **tokens)
{
	t_token	*new_node;

	new_node = *tokens;
	if (new_node->next)
	{
		new_node->next->prev = new_node->prev;
		new_node->prev->next = new_node->next;
	}
	else
		new_node->prev->next = NULL;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}
