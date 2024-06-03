#include "../../includes/minishell.h"

void	redirs_execution(t_tree *tree, t_tree *right)
{
	int	fd;
	int	std[2];

	std[0] = STDIN_FILENO;
	std[1] = STDOUT_FILENO;
	fd = open_file(right);
	dup2(fd, std[0]);
	(void)tree;
}

int	open_file(t_tree *branch)
{
	int	fd;

	fd = 0;
	if (branch->type == INPUT)
	{
		fd = open(branch->right->content, O_RDONLY);
		if (fd == -1)
			printf("Error ao abrir o arquivo - INPUT\n");
	}
	else if (branch->type == APPEND)
	{
		fd = open(branch->right->content, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd == -1)
			printf("Error ao abrir e/ou criar o arquivo - APPEND\n");
	}
	else if (branch->type == OUTPUT)
	{
		fd = open(branch->right->content, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
			printf("Error ao abrir e/ou criar o arquivo - OUTPUT\n");
	}
	return (fd);
}
