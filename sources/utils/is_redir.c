#include "../../includes/minishell.h"

int	is_redir(t_token **token)
{
	if ((*token)->type == INPUT || (*token)->type == OUTPUT
		|| (*token)->type == APPEND)
		return (1);
	return (0);
}

int	is_redir_or_heredoc(t_token **token)
{
	if ((*token)->type == INPUT || (*token)->type == OUTPUT
		|| (*token)->type == APPEND || (*token)->type == HEREDOC)
		return (1);
	return (0);
}

int	the_branch_is_redir(t_tree *branch)
{
	if (branch->type == INPUT || branch->type == OUTPUT
		|| branch->type == APPEND || branch->type == HEREDOC)
		return (1);
	return (0);
}
