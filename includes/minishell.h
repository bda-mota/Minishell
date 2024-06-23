/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:43:31 by bda-mota          #+#    #+#             */
/*   Updated: 2024/06/22 13:58:21 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// INCLUDES
# include "../libft/src/libft.h"
# include "structs.h"
# include "token.h"
# include "ast.h"
# include "exec.h"
# include "builtins.h"
# include "heredoc.h"
//LIBRARIES
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>

# define PURPLE	"\001\033[1;35m\002"
# define WHITE	"\001\033[1;37m\002"

/* ==== FREE MEMORY ==== */
void		free_minishell(t_minishell *shell);
void		free_execution(void);
void		free_pipe_child(void);
void		free_simple_child(char **child, char *executable);
void		free_fail_execve(char **child, char *executable);

/* ==== GET_SET ==== */
int			get_status(int status);
char		*get_path(char *path);
char		***get_env_copy(char **copy);
t_minishell	*get_minishell(t_minishell *shell);

/* ==== SIGNALS ==== */
void		initialize_signals(void);
void		signal_readline(int signal);
void		signal_execution(int pid);
void		signal_heredoc(void);
void		handler_heredoc(int signal);
void		signal_readline_in_execution(int signal);
void		signal_readline_in_pipe(int signal);
void		signal_pipe(int pid);
void		free_pipe(void);

/* ==== UTILS ==== */
int         check_spaces(char *str);
void		init_shell(t_minishell *shell);
void		init_structs(t_minishell *shell);
void		processor(t_minishell *shell);
int			is_redir(t_token **token);
int			is_redir_or_heredoc(t_token **token);
int			the_branch_is_redir(t_tree *branch);

/* EXCLUIR AO FINAL DO PROJETO */
void		print_list(t_token **lst);
void		print_tree(t_tree *tree);
void		print_tree_main(t_tree *tree);
void		print_tree_aux(t_tree *tree, int depth, const char *relation);
void		print_redir(t_redir *redirs);

#endif
