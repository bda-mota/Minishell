/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rearrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:49:00 by bda-mota          #+#    #+#             */
/*   Updated: 2024/06/21 14:49:02 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_token	*rearrange_aux(t_token **tokens);
static t_token	*find_redir(t_token **redir);

void	rearrange_tokens(t_token **tokens)
{
	t_token	*curr;

	curr = *tokens;
	while (curr)
	{
		if (is_redir_or_heredoc(&curr) && curr->next)
		{
			while (check_pipeline(&curr) == 1)
			{
				curr = rearrange_aux(&curr);
				curr = curr->next;
			}
		}
		curr = curr->next;
	}
	if ((*tokens)->prev)
		*tokens = (*tokens)->prev;
}

static t_token	*rearrange_aux(t_token **tokens)
{
	t_token	*word;
	t_token	*first;
	t_token	*redir;

	word = *tokens;
	redir = get_first_node_of_pipeline(&word);
	first = (get_first_word(&redir));
	redir = find_redir(&redir);
	while (word)
	{
		if (!is_redir_or_heredoc(&word) && word->type != ARCHIVE)
		{
			word = split_list(&word);
			break ;
		}
		word = word->next;
	}
	word->prev = first;
	if (first)
		first->next = word;
	word->next = redir;
	redir->prev = word;
	if (word && word->prev == NULL)
		*tokens = word;
	return (word);
}

static t_token	*find_redir(t_token **redir)
{
	while (redir && !is_redir_or_heredoc(redir))
		redir = &(*redir)->next;
	return (*redir);
}

t_token	*split_list(t_token **tokens)
{
	t_token	*new_node;

	new_node = *tokens;
	if (new_node->next)
	{
		if (new_node->prev)
			new_node->next->prev = new_node->prev;
		new_node->prev->next = new_node->next;
	}
	else
		new_node->prev->next = NULL;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	inspect_types(t_token **tokens)
{
	t_token	*curr;

	curr = *tokens;
	while (curr)
	{
		if (is_redir_or_heredoc(&curr))
		{
			if (curr->next)
				curr->next->type = ARCHIVE;
		}
		curr = curr->next;
	}
}
