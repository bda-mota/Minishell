#include "../../includes/minishell.h"

int	has_heredoc(t_token *token)
{
	t_token	*curr;

	curr = token;
	while (curr)
	{
		if (curr->type == HEREDOC)
			return (0);
		curr = curr->next;
	}
	return (1);
}

t_token	*get_heredoc(t_token *token)
{
	t_token	*curr;

	curr = token;
	while (curr)
	{
		if (curr->type == HEREDOC)
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}

void	remove_heredoc(t_token **token, t_token **heredoc, char *path)
{
	t_token	*delimiter;

	delimiter = (*heredoc)->next;
	if (delimiter->next)
	{
		(*heredoc)->next = delimiter->next;
		delimiter->next->prev = *heredoc;
	}
	else
		(*heredoc)->next = NULL;
	free(delimiter->content);
	free(delimiter);
	if (!(*heredoc)->prev && !(*heredoc)->next)
		deallocate_lst(token);
	else
	{
		(*heredoc)->content = ft_strdup(path);
		(*heredoc)->type = ARCHIVE;
	}
}
