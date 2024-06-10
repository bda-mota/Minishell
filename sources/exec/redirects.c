#include "../../includes/minishell.h"

void	redirs_execution(t_tree *tree, t_tree *right)
{
	int	fd;
	int	saved_std[2];

	(void)right;
	saved_std[0] = dup(STDIN_FILENO);
	saved_std[1] = dup(STDOUT_FILENO);
	open_file(tree, &fd);
	dup_file(tree, &fd);
	if (tree->left)
		executor(tree->left);
	dup2(saved_std[0], STDIN_FILENO);
	dup2(saved_std[1], STDOUT_FILENO);
	close(saved_std[0]);
	close(saved_std[1]);
}

int	open_file(t_tree *tree, int *fd)
{
	if (tree && tree->type == INPUT)
		*fd = open(tree->right->content, O_RDONLY);
	else if (tree && tree->type == APPEND)
		*fd = open(tree->right->content, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (tree && tree->type == OUTPUT)
		*fd = open(tree->right->content, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*fd == -1)
		return (display_error_exec("no_file", tree->right->content));
	return (EXIT_SUCCESS);
}

int	dup_file(t_tree *tree, int *fd)
{
	if (tree && tree->type == INPUT)
	{
		if (*fd != -1 && *fd != STDIN_FILENO)
		{
			dup2(*fd, STDIN_FILENO);
			close(*fd);
			return (EXIT_SUCCESS);
		}
	}
	else if (tree->type == OUTPUT || tree->type == APPEND)
	{
		if (*fd != -1 && *fd != STDOUT_FILENO)
		{
			dup2(*fd, STDOUT_FILENO);
			close(*fd);
			return (EXIT_SUCCESS);
		}
	}
	return (EXIT_FAILURE);
}
