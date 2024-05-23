#include "../../includes/minishell.h"

void	pipe_execution(t_tree *node, t_exec **execution)
{
	int		tube[2];
	int		pid;
	t_tree	*aux;

	aux = node;
	pipe(tube);
	pid = fork();
	if (pid == -1)
	{
		close(tube[0]);
		close(tube[1]);
		printf("Error\n");
	}
	if (pid == 0)
	{
		close(tube[0]);
	}
	(void)execution;
}

// int	open_tube(t_exec *execution)
// {
// 	if (pipe(execution->tube) == -1)
// 	{
// 		printf("Error\n");
// 	}
// 	return (EXIT_SUCCESS);
// }

// void	close_tubes(t_exec *execution)
// {
// 	close(execution->tube[0]);
// 	close(execution->tube[1]);
// }
