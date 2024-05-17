#include "../../includes/minishell.h"
<<<<<<< HEAD

char	*check_command(t_exec *execution)
{
	char	*command;
	char	*complete_command;

	command = execution->argv_child[0];
	if (access(command, X_OK) == 0)
		return (command);
	complete_command = add_cmd_env(execution, command);
	return (complete_command);
}
=======
>>>>>>> 6c29cc85d39cefacb9ecf996700fd7c6f849e5d1
