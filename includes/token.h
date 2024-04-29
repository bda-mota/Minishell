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
int		catalog_inputs(char *c);

//SEPARATORS
int		ft_handle_quote(char *input);
void	handle_quote(t_token **token_h, char *input, size_t *i, size_t size);
void	handle_word(t_token **token_h, char *input, size_t *i);
void	handle_inputs(t_token **token_h, char *input, size_t *i);

#endif

