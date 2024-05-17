#include "../../includes/minishell.h"

char	*check_command(t_exec *execution)
{
	char	*command;
	char	*complete_command;

	command = pipex->argv_child[0];
	if (access(command, X_OK) == 0)
		return (command);
	complete_command = add_cmd_env(pipex, command);
	return (complete_command);
}
