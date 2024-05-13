#include "../../includes/minishell.h"

void	inspect_types(t_token **tokens)
{
	t_token	*curr;

	curr = *tokens;
	while (curr)
	{
		if (curr->type == INPUT || curr->type == OUTPUT || curr->type == APPEND)
		{
			if (curr->next)
				curr->next->type = ARCHIVE;
		}
		else if (curr->type == PIPE)
		{
			if (curr->prev)
				curr->prev->type = COMMAND;
			if (curr->next)
				curr->next->type = COMMAND;
		}
		else if (curr->type == HEREDOC)
		{
			if (curr->next)
				curr->next->type = DELIMITER;
		}
		curr = curr->next;
	}
}
