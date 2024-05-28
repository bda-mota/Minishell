#include "../../includes/minishell.h"

char	*get_path(char *path)
{
	static char	*new_path;

	if (path != NULL)
		new_path = path;
	return (new_path);
}

char	***get_env_copy(char **copy)
{
	static char	**s_copy;

	if (copy != NULL)
		s_copy = &*copy;
	return (&s_copy);
}

char	**get_paths(char **paths)
{
	static char	**new;

	if (paths != NULL)
		new = &*paths;
	return (new);
}

t_tree	*get_tree(t_tree *tree)
{
	static t_tree	*new;

	if (tree != NULL)
		new = tree;
	return (new);
}

t_minishell	*get_minishell(t_minishell *shell)
{
	static t_minishell	*new;

	if (shell != NULL)
		new = shell;
	return (new);
}
