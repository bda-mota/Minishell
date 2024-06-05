#include "../../includes/minishell.h"

void	close_all(void)
{
	int	i;

	i = 0;
	while (i < 1024)
		close(i++);
}

void	close_tubes(int *tube)
{
	close(tube[0]);
	close(tube[1]);
}

void	wait_forks(pid_t *pid, int status)
{
	waitpid(pid[0], &status, 0);
	waitpid(pid[1], &status, 0);
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
