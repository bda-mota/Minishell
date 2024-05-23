#include "../../includes/minishell.h"


void	export(char *new_variable, t_minishell **env)
{
	char	**original_environ;

	original_environ = NULL;
	(*env)->env_copy = add_variable_to_environ(original_environ, new_variable);
	if (!(*env)->env_copy)
	{
		ft_free_matrix(original_environ);
		return ;
	}
}
