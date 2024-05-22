#include "../../includes/minishell.h"

void	echo(t_token **tokens)
{
	t_token	*curr;
	int		flag;

	curr = *tokens;
	flag = 0;

	while (curr && ft_strcmp("-n", curr->content) == 0)
	{
		flag = 1;
		curr = curr->next;
	}
	while (curr)
	{
		ft_printf_fd("%s", curr->content);
		if (curr->next != NULL)
			ft_printf_fd(" ");
		curr = curr->next;
	}
	if (!flag)
		ft_printf_fd("\n");
}
