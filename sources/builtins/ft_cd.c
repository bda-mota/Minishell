/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:45:33 by bda-mota          #+#    #+#             */
/*   Updated: 2024/06/21 14:45:34 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_arguments(char *path);

static void	variables_update(char **env_copy,
	char *var_name, char *new_var, int var_len)
{
	int		i;
	char	*new_env;
	char	*new_value_start;
	int		size_var;

	i = 0;
	while (env_copy[i])
	{
		if (ft_strncmp(env_copy[i], var_name, var_len) == 0
			&& env_copy[i][var_len] == '=')
		{
			new_value_start = ft_strchr(env_copy[i], '=');
			new_value_start++;
			size_var = var_len + 1 + ft_strlen(new_var) + 1;
			new_env = ft_calloc(size_var, 1);
			if (!new_env)
				return ;
			ft_strncpy(new_env, env_copy[i], var_len + 1);
			ft_strcpy(new_env + var_len + 1, new_var);
			free(env_copy[i]);
			env_copy[i] = new_env;
		}
			i++;
	}
}

static void	update_pwd_vars(char **env_copy, char *old_pwd, char *pwd)
{
	if (old_pwd)
	{
		variables_update(env_copy, "OLDPWD", old_pwd, 6);
		free(old_pwd);
	}
	if (pwd)
	{
		variables_update(env_copy, "PWD", pwd, 3);
		free(pwd);
	}
}

static int	chance_directory(char *path)
{
	if (path == NULL || ft_strcmp(path, "~") == 0)
	{
		path = ft_getenv(*get_env_copy(NULL), "HOME");
		if (path == NULL)
		{
			ft_printf_fd(STDERR_FILENO,
				"cd: Could not get the home directory.\n");
			get_status(1);
			return (1);
		}
	}
	if (check_arguments(path) == 1)
		return (1);
	if (chdir(path) != 0)
	{
		ft_printf_fd(STDERR_FILENO, "cd: %s: No such file or directory\n", path);
		get_status(1);
		return (1);
	}
	get_status(0);
	return (0);
}

static int	check_arguments(char *path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		if (ft_isspace(path[i]) == 1)
		{
			ft_printf_fd(STDERR_FILENO, "cd: %s: too many arguments\n", path);
			get_status(1);
			return (1);
		}
		i++;
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
