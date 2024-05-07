#include "../../includes/minishell.h"

t_token	*get_last_node(t_token **list)
{
	t_token	*last_node;

	last_node = *list;
	if (*list == NULL)
		return (NULL);
	while (last_node->next != NULL)
		last_node = last_node->next;
	printf("%s", last_node->content);
	return (last_node);
}
