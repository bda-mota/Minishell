#include "../../includes/minishell.h"

// Ao mandar apenas o export sem argumento deixar na ordem e printar "declare -x"

void	export(t_minishell *shell, char *new_variable)
{
	add_variable_to_environ(shell, new_variable);
}
