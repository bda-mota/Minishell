#include "../../includes/minishell.h"

int	check_sintax(char *input)
{
	if (!check_untreatable(input) || !check_blocks(input)
		|| !check_quotes(input))
	{
		get_status(2);
		return (0);
	}
	return (1);
}

int	check_grammar(t_token **token)
{
	t_token	*curr;

	curr = *token;
	while (curr)
	{
		if (is_invalid_redir_or_heredoc(curr))
		{
			display_error_tokens("newline", curr->content[0]);
			deallocate_lst(token);
			return (0);
		}
		else if (is_invalid_pipe(curr))
		{
			display_error_tokens("sintaxe", curr->content[0]);
			deallocate_lst(token);
			return (0);
		}
		curr = curr->next;
	}
	return (1);
}


int	is_invalid_redir_or_heredoc(t_token *curr)
{
	return (is_redir_or_heredoc(&curr)
		&& (!curr->next || (curr->next->type != WORD
				&& curr->next->type != SIMPLE
				&& curr->next->type != DOUBLE)));
}

int	is_invalid_pipe(t_token *curr)
{
	return (curr->type == PIPE && ((!curr->prev || !curr->next)
			|| (curr->prev->type != WORD && curr->prev->type != SIMPLE
				&& curr->prev->type != DOUBLE) || (curr->next->type != WORD
				&& curr->next->type != SIMPLE && curr->next->type != DOUBLE)));
}

