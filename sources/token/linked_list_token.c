#include "../../includes/minishell.h"

void	init_token(t_token **token)
{
	*token = malloc(sizeof(t_token));
	if (!*token)
		return ;
	(*token)->content = NULL;
	(*token)->next = NULL;
	(*token)->prev = NULL;
}

void	insert_token(t_token **token, char *content, int type)
{
	t_token	*new_node;

	new_node = malloc(sizeof(t_token));
	if (!new_node)
		return ;
	new_node->content = ft_strdup(content);
	new_node->type = type;
	new_node->next = NULL;
	new_node->prev = *token;
	(*token)->next = new_node;
	*token = new_node;
	free(content);
}

void	deallocate_lst(t_token **token)
{
	t_token	*curr;
	t_token	*temp;

	if (*token == NULL)
		return ;
	curr = *token;
	while (curr != NULL)
	{
		temp = curr->next;
		free(curr->content);
		free(curr);
		curr = temp;
	}
	*token = NULL;
}

void	remove_first(t_token **token)
{
	t_token	*curr;

	if (*token == NULL)
		return ;
	if ((*token)->content != NULL)
		return ;
	curr = *token;
	*token = (*token)->next;
	(*token)->prev = NULL;
	free(curr);
}
