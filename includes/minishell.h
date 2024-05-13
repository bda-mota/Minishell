#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/src/libft.h"
# include "structs.h"
# include "token.h"
# include "ast.h"
# include <stdio.h>
# include <signal.h>
# include <unistd.h>
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

/* EXCLUIR AO FINAL DO PROJETO */
void	print_list(t_token **lst);

#endif
