#include "../../includes/minishell.h"

// Reformular para encontrar na árvore e identificar se é builtin a partir deste ponto

void	find_builtins(t_token **token, t_minishell **env)
{
	t_token	*curr;

	curr = *token;
	while (curr)
	{
		if (ft_strcmp("echo", curr->content) == 0)
			echo(&curr->next);
		if (ft_strcmp("pwd", curr->content) == 0)
			pwd();
		if (ft_strcmp("export", curr->content) == 0)
			return ;
		if (ft_strcmp("env", curr->content) == 0)
			return ;
		curr = curr->next;
			//env((*env)->env_copy);
			//export(curr->next->content, (*env)->env_copy);
		(void)env;
	}
}

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
		else if (ft_strcmp("pwd", curr->content) == 0)
			pwd();
		else if (ft_strcmp("export", curr->content) == 0)
			export(shell, curr->next->content);
		else if (ft_strcmp("env", curr->content) == 0)
			env(shell);
		else if (ft_strcmp("unset", curr->content) == 0)
			unset(shell, curr->next->content);
		curr = curr->next;
	}
}
