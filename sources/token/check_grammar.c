#include "../../includes/minishell.h"

int	is_invalid_redir_or_heredoc(t_token *curr)
{
	return (is_redir_or_heredoc(&curr)
		&& (!curr->next || curr->next->type != WORD));
}

int	is_invalid_pipe(t_token *curr)
{
	return (curr->type == PIPE && ((!curr->prev || !curr->next)
			|| (curr->prev->type != WORD || curr->next->type != WORD)));
}

int	check_grammar(t_token **token)
{
	t_token	*curr;

	curr = *token;
	while (curr)
	{
		if (is_invalid_redir_or_heredoc(curr) || is_invalid_pipe(curr))
		{
			display_error_tokens("sintaxe", curr->content[0]);
			deallocate_lst(token);
			get_status(2);
			return (1);
		}
		curr = curr->next;
	}
	return (0);
}

