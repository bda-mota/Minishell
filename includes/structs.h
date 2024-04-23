#ifndef STRUCTS_H
# define STRUCTS_H

# include "../libft/src/libft.h"

enum e_numerator {
	PIPE,
	REDIRECT,
	WORD,
	ARCHIVE,
	HEREDOC,
	DOUBLE,
	SIMPLE,
	BLOCK
};

typedef struct s_token {
	int				type;
	char			*content;
	struct s_token	*next;
}	t_token;

#endif
