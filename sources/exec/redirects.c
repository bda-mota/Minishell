#include "../../includes/minishell.h"

void	redirs_execution(t_tree *tree, t_tree *right)
{
	int	fd;
	int	std[2];

	std[0] = STDIN_FILENO;
	std[1] = STDOUT_FILENO;
	fd = open_file(tree, right);
	if (tree->type == INPUT)
	{
		if (fd != -1 && fd != 0)
		{
			dup2(fd, std[0]);
			get_minishell(NULL)->fd_input = fd;
			close(fd);
		}
	}
	else if (tree->type == OUTPUT || tree->type == APPEND)
	{
		if (fd != -1 && fd != 1)
		{
			dup2(fd, std[1]);
			get_minishell(NULL)->fd_output = fd;
			close(fd);
		}
	}
}

int	open_file(t_tree *tree, t_tree *right)
{
	int	fd;

	(void)right;
	if (tree && tree->type == INPUT)
	{
		fd = open(right->content, O_RDONLY);
		if (fd == -1)
			printf("Error ao abrir o arquivo - INPUT\n");
		return (fd);
	}
	else if (tree && tree->type == APPEND)
	{
		fd = open(right->content, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd == -1)
			printf("Error ao abrir e/ou criar o arquivo - APPEND\n");
		return (fd);
	}
	else if (tree && tree->type == OUTPUT)
	{
		fd = open(right->content, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
			printf("Error ao abrir e/ou criar o arquivo - OUTPUT\n");
		return (fd);
	}
	return (-1);
}
