#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/src/libft.h"
# include "structs.h"
# include "token.h"
# include <stdio.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

# define PURPLE	"\033[1;35m"
# define WHITE	"\033[1;37m"
# define WARNING_OR "The BaBy do not work with '||' or '&&'\n"

//UTILS
void	display_error(char *error, char c);
void	found_sintaxe(char *str, t_token **token_tail, t_token **token_h);
t_token	*get_last_node(t_token **list);
int		get_list_size(t_token *list);
t_token	*search_delimiter(t_token **tokens);;
t_tree	*create_root(t_token *tokens);
void	bloom_tree(t_tree **root, t_tree *new_branch, int side);
void	build_tree(t_tree **root, t_token **tokens, int side);
void    free_leaves(t_tree *root);
void    free_tree(t_tree *root);

/* EXCLUIR AO FINAL DO PROJETO */
# include <unistd.h>
void	print_list(t_token **lst);

#endif
