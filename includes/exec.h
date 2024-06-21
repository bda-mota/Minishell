/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:43:20 by bda-mota          #+#    #+#             */
/*   Updated: 2024/06/21 14:43:22 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "../libft/src/libft.h"
# include "structs.h"

/* ==== COMMAND ==== */
void	check_command(t_tree *tree, char *command);
void	find_command(t_tree *tree, char *cmd);

/* ==== EXECUTION ==== */
int		executor(t_tree *tree);
int		execute(t_tree *tree, char *command);
void	set_status(int status);

/* ==== TREAT ERRORS ==== */
void	treat_errors(t_tree *tree, int *status);
int		is_directory(const char *path);
void	print_execve_error(char *command, int type);

/* ==== REDIRECTS ==== */
int		redirs_execution(t_tree *tree);
int		dup_file(t_tree *tree, int *fd);
int		open_file(t_tree *tree, int *fd);

/* ==== PIPE ==== */
int		pipe_execution(t_tree *left, t_tree *right);
int		open_tubes(int *tube);
void	first_child(t_tree *left, int *tube);
void	second_child(t_tree *right, int *tube);
void	close_tubes(int *tube);
void	close_all(void);
void	fork_error(void);

/* ==== PATH ==== */
void	find_path(t_minishell *shell);
void	build_path(t_minishell *shell);

#endif
