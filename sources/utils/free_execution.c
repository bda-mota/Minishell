#include "../../includes/minishell.h"

void	free_execution(t_tree *tree, char *input)
{
	if (input)
		free (input);
	if (tree && tree->command_child)
		ft_free_matrix(tree->command_child);
	if (tree && tree->path_cmd)
		ft_free_matrix(tree->path_cmd);
	if (tree)
	{
		down_tree(&tree);
	}
}

void	free_child(void)
{
	t_tree	*tree;
	char	*path_shell;
	char	**env_copy;
	char	**paths_cmd;

	tree = get_tree(NULL);
	env_copy = *get_copy(NULL);
	paths_cmd = get_paths_cmd(NULL);
	path_shell = get_path(NULL);
	tree = NULL;
	if (paths_cmd)
		ft_free_matrix(paths_cmd);
	if (tree && tree->command_child)
		ft_free_matrix(tree->command_child);
	if (tree && tree->path_cmd)
		ft_free_matrix(tree->path_cmd);
	if (tree)
		down_tree(&tree);
	//if (env)
	//	ft_free_matrix(env);
	//if (path)
	//	free(path);
}
