#include "../../includes/minishell.h"

// Reformular para encontrar na árvore e identificar se é builtin a partir deste ponto

void	find_builtins(t_minishell *shell)
{
	t_token	*curr;

	curr = shell->token;
	while (curr)
	{
		if (ft_strcmp("echo", curr->content) == 0)
			echo(&curr->next);
		if (ft_strcmp("pwd", curr->content) == 0)
			pwd();
		if (ft_strcmp("export", curr->content) == 0)
			export(curr->next->content, shell);
		if (ft_strcmp("env", curr->content) == 0)
			env(shell);
		curr = curr->next;
	}
}
