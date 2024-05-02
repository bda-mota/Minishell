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

void	insert_token(t_token **token_head, char *content, int type)
{
	t_token	*new_node;

	new_node = malloc(sizeof(t_token));
	if (!new_node)
		return ;
	new_node->content = ft_strdup(content);
	new_node->type = type;
	new_node->next = NULL;
	new_node->prev = *token_head;
	(*token_head)->next = new_node;
	*token_head = new_node;
	free(content);
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
		temp = curr->next;
		free(curr->content);
		free(curr);
		curr = temp;
	}
	*tail = NULL;
	*head = NULL;
}

void	remove_first(t_token **token)
{
	t_token	*curr;

	if ((*token)->content != NULL)
		return ;
	curr = *token;
	*token = (*token)->next;
	(*token)->prev = NULL;
	free(curr);
}
