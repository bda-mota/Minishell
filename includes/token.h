#ifndef TOKEN_H
# define TOKEN_H

# include "../libft/src/libft.h"
# include "structs.h"

void	insert_token(t_token **token, char *content);
void	deallocate_lst(t_token **token);
void	classifier_inputs(t_token **token);

#endif

