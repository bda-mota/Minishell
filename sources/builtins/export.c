#include "../../includes/minishell.h"

void	export(char *new_variable, t_minishell *shell)
{
	add_variable_to_environ(shell, new_variable);
}
