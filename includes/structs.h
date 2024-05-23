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
	struct s_tree	*right;
	struct s_tree	*left;
}	t_tree;

typedef struct s_exec
{
	//t_tree	*cmd;
	char	*complete_path;
	char	**paths;
	char	**env;
	char	**env_copy;
	char	**command_child;
	int		tube[2];
	int		pipe_fd;
}	t_exec;

typedef struct s_minishell
{
	t_tree	*tree;
	t_exec	*exec;
	t_token	*token;
	char	*input;
}	t_minishell;

#endif
