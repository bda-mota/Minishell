#include "../../includes/minishell.h"

void	init_shell(t_minishell *shell)
{
	shell->complete_path = NULL;
	shell->paths = NULL;
	shell->env_copy = NULL;
	shell->status = 0;
	shell->cmd_args = NULL;
	get_status(0);
}

void	init_structs(t_minishell *shell)
{
	shell->token = NULL;
	shell->tree = NULL;
}
