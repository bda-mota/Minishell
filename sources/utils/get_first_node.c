#include "../../includes/minishell.h"

t_token	*get_first_node(t_token **list)
{
	t_token	*first_node;

	first_node = *list;
	if (*list == NULL)
		return (NULL);
	while (first_node->prev != NULL)
		first_node = first_node->prev;
	return (first_node);
}
