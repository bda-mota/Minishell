#ifndef STRUCTS_H
# define STRUCTS_H

# include "../libft/src/libft.h"

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
typedef struct s_data_token
{ // struct não implementada ainda
	int		size;
	t_token	*first;
	t_token	*last;
}	t_data_token;

typedef struct s_tree
{
	int				type;
	char			*content;
	struct s_tree	*right;
	struct s_tree	*left;
}	t_tree;

typedef struct s_exec
{
	char	*complete_path;
	char	**paths;
	char	**env;
}	t_exec;

#endif
