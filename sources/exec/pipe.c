#include "../../includes/minishell.h"

void	pipe_execution(t_tree *node, t_exec **execution)
{
	int		fd[2];
	int		pid;
	t_tree	*aux;

	aux = node;
	pipe(fd);
	pid = fork();
	if (pid == -1)
	{
		close(fd[0]);
		close(fd[1]);
		printf("Error\n");
	}
	(void)execution;
}

int	open_tube(t_exec *execution)
{
	if (pipe(execution->tube) == -1)
	{
		printf("Error\n");
	}
	return (EXIT_SUCCESS);
}

void	close_tubes(t_exec *execution)
{
	close(execution->tube[0]);
	close(execution->tube[1]);
}
