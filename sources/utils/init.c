#include "../../includes/minishell.h"

void	init_shell(t_minishell *shell)
{
	shell->complete_path = NULL;
	shell->paths = NULL;
	shell->env_copy = NULL;
	shell->status = 0;
	shell->saved_std[0] = dup(STDIN_FILENO);
	shell->saved_std[1] = dup(STDOUT_FILENO);
	get_status(0);
}

void	init_structs(t_minishell *shell)
{
	shell->token = NULL;
	shell->tree = NULL;
}
