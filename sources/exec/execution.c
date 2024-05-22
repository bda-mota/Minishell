#include "../../includes/minishell.h"

void	implement(t_exec **execution, char *command)
{
	char	*executable;

	(*execution)->command_child = ft_split(command, ' ');
	if ((*execution)->command_child == NULL)
		printf("Error\n");
	executable = check_command((*execution));
	if (executable == NULL)
		printf("Error\n");
	execve(executable, (*execution)->command_child, (*execution)->env);
}

char	*check_command(t_exec *execution)
{
	char	*command;
	char	*complete_command;

	command = execution->command_child[0];
	if (access(command, X_OK) == 0)
		return (command);
	complete_command = add_command_to_path(&execution, command);
	return (complete_command);
}
