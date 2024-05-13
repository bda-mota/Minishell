#include "../../includes/minishell.h"

void	inspect_types(t_token **tokens)
{
	t_token	*curr;

	curr = *tokens;
	while (curr)
	{
		if (curr->type == INPUT)
			curr->prev->type = ARCHIVE;
		else if (curr->type == OUTPUT)
			curr->next->type = ARCHIVE;
		else if (curr->type == APPEND)
			curr->prev->type = ARCHIVE;
		else if (curr->type == PIPE)
		{
			curr->prev->type = COMMAND;
			curr->next->type = COMMAND;
		}
		else if (curr->type == HEREDOC)
			curr->next->type = DEMILITER;
		curr = curr->next;
	}
}
