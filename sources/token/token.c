
#include "../../includes/minishell.h"

void	insert_token(t_token **stack, char *content)
{
	t_token	*curr;
	t_token	*new_node;

	new_node = malloc(sizeof(t_token));
	if (!new_node)
		return ;
	new_node->content = ft_strdup(content);
	new_node->next = NULL;
	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	curr = *stack;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new_node;
}

void	deallocate_lst(t_token **stack)
{
	t_token	*curr;
	t_token	*tmp;

	curr = *stack;
	while (curr)
	{
		tmp = curr;
		curr = curr->next;
		free (tmp);
	}
	*stack = NULL;
}
