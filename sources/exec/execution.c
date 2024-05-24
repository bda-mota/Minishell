#include "../../includes/minishell.h"

void	direct_to_exec(t_tree **root, t_exec **execution)
{
	t_tree	*aux;

	aux = traverse_tree(root);
	(void)execution;
	if (aux->type == PIPE)
	{
		pipe_execution(aux, execution);
	}
	else
	{
		implement(execution, aux->content);
	}
}

void	implement(t_exec **execution, char *command)
{
	char	*executable;
	int		pid;

	pid = fork();
	if (pid == 0)
	{
		(*execution)->command_child = ft_split(command, ' ');
		if ((*execution)->command_child == NULL)
			printf("Error ao dar split\n");
		executable = check_command((*execution));
		if (executable == NULL)
			exit(1);
		execve(executable, (*execution)->command_child, (*execution)->env);
	}
	wait(NULL);
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
