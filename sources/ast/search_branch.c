#include "../../includes/minishell.h"

t_token	**search_branchs(t_token **tokens)
{
	t_token	**curr;
	t_token	*meta;

	curr = ft_calloc(3, sizeof(t_token *));
	if (!curr)
		return (NULL);
	meta = search_pipe(tokens);
	if (meta)
	{
		*curr = define_ptrs(meta, curr, PIPE);
		return (curr);
	}
	meta = search_redirs(tokens);
	if (meta)
	{
		*curr = define_ptrs(meta, curr, REDIRECT);
		return (curr);
	}
	curr[0] = NULL;
	curr[1] = put_all_together(tokens);
	curr[2] = NULL;
	return (curr);
}

t_token	*define_ptrs(t_token *meta, t_token **curr, int type)
{
	if (type == PIPE)
	{
		curr[0] = meta->prev;
		curr[0]->next = NULL;
		curr[1] = meta;
		curr[2] = meta->next;
		curr[2]->prev = NULL;
		return (*curr);
	}
	else if (type == REDIRECT)
	{
		curr[0] = new_redir_list(&meta);
		curr[1] = meta;
		curr[2] = meta->next;
		return (*curr);
	}
	return (NULL);
}

t_token	*search_pipe(t_token **tokens)
{
	t_token	*curr;

	curr = get_last_node(tokens);
	while (curr && curr->prev)
	{
		if (curr->type == PIPE)
			return (curr);
		curr = curr->prev;
	}
	return (NULL);
}

t_token	*search_redirs(t_token **tokens)
{
	t_token	*curr;

	curr = get_first_node(tokens);
	while (curr && curr->next)
	{
		if (is_redir_or_heredoc(&curr))
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}

t_token	*new_redir_list(t_token **token_list)
{
	t_token	*curr;

	curr = *token_list;
	if (curr->prev)
	{
		if (curr->next->next)
			curr->prev->next = curr->next->next;
		else
			curr->prev->next = NULL;
	}
	if (curr->next->next)
	{
		if (curr->prev)
			curr->next->next->prev = curr->prev;
		else
			curr->next->next->prev = NULL;
	}
	if (curr->prev == NULL)
		return (NULL);
	while (curr->prev && curr->prev->type != PIPE)
		curr = curr->prev;
	return (curr);
}
