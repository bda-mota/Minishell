#include "../../includes/minishell.h"

void	close_all(void)
{
	int	i;

	i = 0;
	while (i < 1024 && i > 2)
		close(i++);
}

void	fork_error(void)
{
	ft_printf_fd(STDERR_FILENO, "Error: %s\n", strerror(errno));
	exit(EXIT_FAILURE);
}

void	close_tubes(int *tube)
{
	close(tube[0]);
	close(tube[1]);
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
