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
	char			**path_cmd;
	char			**command_child;
	char			**env_copy;
	struct s_tree	*right;
	struct s_tree	*left;
}	t_tree;

typedef struct s_exec
{
	char	**path_cmd;
	char	**command_child;
}	t_exec;

typedef struct s_minishell
{
	t_tree	*tree;
	t_exec	*exec;
	t_token	*token;
	char	*input;
	char	*complete_path; // caminho de PATH= - > dar free só no final (?)
	char	**env_copy; // copia do env com as variáveis de ambiente -> builtins (usar no execve?)
	char	**paths; // path splitado e com / no final -> dar free só no final
}	t_minishell;

#endif
