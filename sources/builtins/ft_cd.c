#include "../../includes/minishell.h"

static void	update_pwd_vars(char **env_copy, char *old_pwd, char *pwd)
{
	if (old_pwd)
	{
		update_variable(env_copy, "OLDPWD", old_pwd, 6);
		free(old_pwd);
	}
	if (pwd)
	{
		update_variable(env_copy, "PWD", pwd, 3);
		free(pwd);
	}
}

static int	chance_directory(char *path)
{
	if (path == NULL || ft_strcmp(path, "~") == 0)
	{
		path = getenv("HOME");
		if (path == NULL)
		{
			ft_printf_fd("cd: Could not get the home directory.\n", 2);
			return (1);
		}
	}
	if (chdir(path) != 0)
	{
		ft_printf_fd("cd: %s: No such file or directory\n", path, 2);
		return (1);
	}
	return (0);
}

void	ft_cd(char *path)
{
	char	*old_pwd;
	char	*pwd;
	char	**env_copy;

	env_copy = *get_env_copy(NULL);
	old_pwd = getcwd(NULL, 0);
	if (chance_directory(path) != 0)
	{
		free(old_pwd);
		return ;
	}
	pwd = getcwd(NULL, 0);
	update_pwd_vars(env_copy, old_pwd, pwd);
}
