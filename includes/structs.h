/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:43:38 by bda-mota          #+#    #+#             */
/*   Updated: 2024/06/21 16:27:28 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../libft/src/libft.h"

/* ======= ENUMS ======== */
enum e_numerator
{
	SSPACE,
	PIPE,
	INPUT,
	OUTPUT,
	WORD,
	HEREDOC,
	APPEND,
	DOUBLE,
	SIMPLE,
	BLOCK,
	ARCHIVE,
	DELIMITER,
	REDIRECT,
	OR
};

enum e_size
{
	LEFT,
	RIGHT
};

/* ======= TOKEN ======== */
typedef struct s_token
{
	int				type;
	char			*content;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

/* ======== AST ======== */
typedef struct s_tree
{
	int				type;
	char			*content;
	char			*executable;
	char			**command_child;
	struct s_tree	*right;
	struct s_tree	*left;
}	t_tree;

/* ==== REDIRECTS ==== NÃO IMPLEMENTADA AINDA */
typedef struct s_redir
{
	int				fd;
	int				type;
	struct s_redir	*next;
}	t_redir;

/* ===== MINISHELL ===== */
typedef struct s_minishell
{
	int			status;
	t_tree		*tree;
	t_token		*token;
	char		*input;
	char		*complete_path;
	char		**env_copy;
	char		**paths;
	char		**cmd_args;
	int			sig_hd;
}	t_minishell;

#endif
