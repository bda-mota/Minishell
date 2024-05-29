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
	COMMAND,
	DELIMITER
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

// ***************** NÃO IMPLEMENTADA AINDA *****************
typedef struct s_files
{
	int				fd_input;
	int				fd_output;
	struct s_files	*next;
	struct s_files	*prev;
}	t_files;

typedef struct s_minishell
{
	t_tree	*tree;
	t_token	*token;
	t_files	*files;
	char	*input;
	char	*complete_path;
	char	**env_copy;
	char	**paths;
}	t_minishell;

#endif
