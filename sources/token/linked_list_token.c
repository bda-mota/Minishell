#include "../../includes/minishell.h"

void	init_token(t_token **tail, t_token **head)
{
	*tail = malloc(sizeof(t_token));
	if (!*tail)
		return ;
	(*tail)->content = NULL;
	(*tail)->next = NULL;
	(*tail)->prev = NULL;
	*head = *tail;
}

void	insert_token(t_token **token_tail, char *content)
{
	t_token	*new_node;

	new_node = malloc(sizeof(t_token));
	if (!new_node)
		return ;
	new_node->content = ft_strdup(content);
	new_node->next = NULL;
	if (*token_tail == NULL)
	{
		new_node->prev = NULL;
		*token_tail = new_node;
	}
	new_node->prev = (*token_tail);
	(*token_tail)->next = new_node;
	(*token_tail) = new_node;
}

void	deallocate_lst(t_token **tail, t_token **head)
{
	t_token	*curr;
	t_token	*temp;

	if (*tail == NULL)
		return ;
	curr = *tail;
	while (curr != NULL)
	{
		temp = curr->prev;
		free(curr->content);
		free(curr);
		curr = temp;
	}
	*tail = NULL;
	*head = NULL;
}
