#include "../../includes/minishell.h"

int	get_list_size(t_token *list)
{
	int	size;

	size = 0;
	if (!list)
		return (0);
	while (list)
	{
		list = list->next;
		size++;
	}
	return (size);
}
