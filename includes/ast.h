#ifndef AST_H
# define AST_H

# include "../libft/src/libft.h"
# include "structs.h"

t_token	*search_delimiter(t_token **tokens);
void	aux_pull_all_together(t_token **new, t_token **curr);
t_token	*put_all_together(t_token **tokens);
t_tree	*create_root(t_token *tokens);
void	bloom_tree(t_tree **root, t_tree *new_branch, int side);
void	build_tree(t_tree **root, t_token **tokens, int side);
void	down_tree(t_tree **root);
int		is_metha(t_token *token);


#endif
