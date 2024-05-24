#include "../../includes/minishell.h"

void	free_execution(t_exec *execution, char *input)
{
	if (input)
		free (input);
	if (execution && execution->command_child)
		ft_free_matrix(execution->command_child);
	if (execution && execution->path_cmd)
		ft_free_matrix(execution->path_cmd);
	if (execution)
		free(execution);
}
