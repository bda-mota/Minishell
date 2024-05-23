#include "../../includes/minishell.h"

void	export(t_minishell *shell, char *new_variable)
{
	add_variable_to_environ(shell, new_variable);
}
