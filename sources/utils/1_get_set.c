#include "../../includes/minishell.h"

int	get_status(int status)
{
	static int	new_status;

	if (status != -1)
		new_status = status;
	return (new_status);
}

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

t_minishell	*get_minishell(t_minishell *shell)
{
	static t_minishell	*new;

	if (shell != NULL)
		new = shell;
	return (new);
}
