#include "../../includes/minishell.h"

void	ft_cd(char *path)
{
	if (path == NULL)
	{
		path = getenv("HOME");
		if (path == NULL)
		{
			ft_printf_fd("cd: Could not get the home directory.\n", 2);
			return ;
		}
	}
	if (chdir(path) != 0)
	{
		ft_printf_fd("cd: %s: No such file or directory\n", path, 2);
		return ;
	}
}
