#ifndef TOKEN_H
# define TOKEN_H

# include "../libft/src/libft.h"
# include "structs.h"

void	init_token(t_token **tail, t_token **head);
void	insert_token(t_token **token_tail, char *content);
void	deallocate_lst(t_token **tail, t_token **head);
void	classifier_inputs(t_token **token);

#endif

