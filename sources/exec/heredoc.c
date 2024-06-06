#include "../../includes/minishell.h"

int	has_heredoc(t_token *token)
{
	t_token	*curr;

	curr = *token;
	while (curr)
	{
		if (curr->type == HEREDOC)
			return (1);
		curr = curr->next;
	}
	return (0);
}
