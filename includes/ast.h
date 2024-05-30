#ifndef AST_H
# define AST_H

# include "../libft/src/libft.h"
# include "structs.h"

/* BUILD TREE */
void	build_tree(t_tree **root, t_token **tokens, int side);
void	bloom_tree(t_tree **root, t_tree *new_branch, int side);

/* TREE UTILS */
t_tree	*create_root(t_token *tokens);
void	down_tree(t_tree **root);
int		is_metha(t_token *token);
void	aux_pull_all_together(t_token **new, t_token **curr);
t_token	*put_all_together(t_token **tokens);

/* SEARCH BRANCH */
t_token	**search_branch(t_token **tokens);
t_token	*search_pipe(t_token **tokens);
t_token	*search_redirs(t_token **tokens);
t_token	*remove_nodes(t_token **token_list);

#endif
