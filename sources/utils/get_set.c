#include "../../includes/minishell.h"

char	*get_path(char *path)
{
	static char	*new_path;

	if (path != NULL)
		new_path = path;
	return (new_path);
}

char	***get_copy(char **copy)
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
