/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:47:42 by bda-mota          #+#    #+#             */
/*   Updated: 2024/06/21 14:47:44 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	treat_errors(t_tree *tree, int *status)
{
	if (access(tree->executable, F_OK) == -1
		&& (ft_strncmp(tree->executable, "/", 1) == 0
			|| ft_strncmp(tree->executable, "./", 2) == 0
			|| ft_strncmp(tree->executable, "../", 3) == 0))
		print_execve_error(tree->executable, 1);
	else if (is_directory(tree->executable) == 1
		&& (ft_strncmp(tree->executable, "/", 1) == 0
			|| ft_strncmp(tree->executable, "./", 2) == 0))
		print_execve_error(tree->executable, 126);
	else if (access(tree->executable, X_OK) == -1
		&& access(tree->executable, F_OK) == 0
		&& access(tree->executable, R_OK | W_OK) == -1)
	{
		ft_printf_fd(STDERR_FILENO, "babyshell: %s: Permission denied\n",
			tree->executable);
		get_status(126);
	}
	else if (get_status(-1) == 127)
		print_execve_error(tree->executable, 127);
	*status = get_status(-1);
	free_fail_execve(tree->command_child, tree->executable);
}

void	print_execve_error(char *command, int type)
{
	if (type == 1)
	{
		ft_printf_fd(STDERR_FILENO,
			"babyshell: %s: No such file or directory\n", command);
		if (get_status(-1) == 127)
			return ;
		get_status(1);
	}
	else if (type == 126)
	{
		ft_printf_fd(STDERR_FILENO, "babyshell: %s: Is a directory\n",
			command);
		get_status(126);
	}
	else if (type == 127)
	{
		ft_printf_fd(STDERR_FILENO, "babyshell: %s: command not found\n",
			command);
		get_status(127);
	}
}

int	is_directory(const char *path)
{
	struct stat	info;

	if (stat(path, &info) != 0)
		return (-1);
	return (S_ISDIR(info.st_mode));
}
