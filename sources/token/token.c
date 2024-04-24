
#include "../../includes/minishell.h"

void	classifier_inputs(t_token **token)
{
	t_token	*curr;

	curr = *token;
	while (curr)
	{
		if (ft_strcmp((curr)->content, "|") == 0)
			(curr)->type = PIPE;
		curr = (curr)->next;
	}
}
