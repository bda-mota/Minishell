#ifndef STRUCTS_H
# define STRUCTS_H

# include "../libft/src/libft.h"

enum e_numerator {
	PIPE,
	INPUT,
	OUTPUT,
	WORD,
	HEREDOC,
	APPEND,
	DOUBLE,
	SIMPLE,
	BLOCK,
	SPACE,
	ARCHIVE
};

typedef struct s_token {
	int				type;
	char			*content;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

#endif
