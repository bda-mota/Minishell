#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/src/libft.h"
# include "structs.h"
# include "token.h"
# include <stdio.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

# define WARNING_SINTAXE "syntax error near unexpected token "
# define WARNING_OR "The minishell do not work with '||'\n"


//UTILS
void	display_error(char *error, char c);
void	found_sintaxe(char *str);


/* EXCLUIR AO FINAL DO PROJETO */
# include <unistd.h>
void	print_list(t_token **lst);

#endif
