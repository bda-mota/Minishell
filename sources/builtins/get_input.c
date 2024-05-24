#include "../../includes/minishell.h"

void	find_builtins(t_minishell *shell)
{
	t_token	*curr;

	curr = shell->token;
	while (curr)
	{
		if (ft_strcmp("echo", curr->content) == 0)
			echo(&curr->next);
		else if (ft_strcmp("pwd", curr->content) == 0)
			pwd();
		else if (ft_strcmp("export", curr->content) == 0)
			export(shell, curr->next->content);
		else if (ft_strcmp("env", curr->content) == 0)
			env(shell);
		else if (ft_strcmp("unset", curr->content) == 0)
			unset(shell, curr->next->content);
		else if (ft_strcmp("cd", curr->content) == 0)
			cd(curr->next->content);
		curr = curr->next;
	}
}
