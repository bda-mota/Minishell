#include "../../includes/minishell.h"

void	ft_cd(char *path)
{
	char	*old_pwd;
	char	*pwd;
	char	**env_copy;

	env_copy = *get_env_copy(NULL);
	old_pwd = getcwd(NULL, 0);
	if (old_pwd)
	{
		update_variable(env_copy, "OLDPWD", old_pwd, 6);
		free(old_pwd);
	}
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
	pwd = getcwd(NULL, 0);
	if (pwd)
	{
		update_variable(env_copy, "PWD", pwd, 3);
		free(pwd);
	}
}
