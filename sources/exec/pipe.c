#include "../../includes/minishell.h"

void	pipe_execution(t_tree *left, t_tree *right)
{
	int		tube[2];
	pid_t	pid[2];

	if (!open_tubes(tube))
		return ;
	pid[0] = fork();
	if (pid[0] == 0)
	{
		close (tube[0]);
		dup2(tube[STDOUT_FILENO], STDOUT_FILENO);
		close (tube[1]);
		direct_to_exec(left);
		close (tube[1]);
		free_pipe_child();
		exit(0);
	}
	pid[1] = fork();
	if (pid[1] == 0)
	{
		close (tube[1]);
		dup2(tube[STDIN_FILENO], STDIN_FILENO);
		close (tube[0]);
		direct_to_exec(right);
		free_pipe_child();
		exit(0);
	}
	close_tubes(tube);
	wait_forks(pid);
}

void	close_tubes(int *tube)
{
	close(tube[0]);
	close(tube[1]);
}

void	wait_forks(pid_t *pid)
{
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
}

int	open_tubes(int *tube)
{
	if (pipe(tube) == -1)
	{
		printf("Erro ao abrir o tubo\n");
		return (0);
	}
	return (1);
}

void	close_all(void)
{
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
}
