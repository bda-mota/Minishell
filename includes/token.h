#ifndef TOKEN_H
# define TOKEN_H

# include "../libft/src/libft.h"
# include "structs.h"

//LINKED LISTS
void	init_token(t_token **tail, t_token **head);
void	deallocate_lst(t_token **tail, t_token **head);
void	insert_token(t_token **token_head, char *content);

//TOKEN
void	course_inputs(t_token **token_h, char *input);

#endif

