#ifndef STRUCTS_H
# define STRUCTS_H

# include "../libft/src/libft.h"

enum e_numerator {
	SSPACE = 0,
	PIPE = 1,
	INPUT = 2,
	OUTPUT = 3,
	WORD = 4,
	HEREDOC = 5,
	APPEND = 6,
	DOUBLE = 7,
	SIMPLE = 8,
	BLOCK = 9,
	ARCHIVE = 10
};

typedef struct s_token {
	int				type;
	char			*content;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

#endif
