#include "../../includes/minishell.h"

// Ao mandar apenas o export sem argumento deixar na ordem e printar "declare -x"

void	export(char **env_copy, char *new_variable)
{
	add_variable_to_environ(env_copy, new_variable);
}
