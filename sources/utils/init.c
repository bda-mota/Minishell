#include "../../includes/minishell.h"

void	init_shell(t_minishell *shell)
{
	shell->complete_path = NULL;
	shell->paths = NULL;
	shell->env_copy = NULL;
}

void	init_structs(t_minishell *shell)
{
	shell->token = NULL;
	shell->tree = NULL;
	shell->files = NULL;
}
