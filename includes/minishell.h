#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/src/libft.h"
# include "structs.h"
# include "token.h"
# include "ast.h"
# include "exec.h"
# include "builtins.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

# define PURPLE	"\033[1;35m"
# define WHITE	"\033[1;37m"
# define WARNING_OR "The BaBy do not work with '||' or '&&'\n"

/* ==== FREE MEMORY ==== */
void		free_minishell(t_minishell *shell);
void		free_execution(t_tree *tree, char *input);
void		free_child(void);

/* ===== ERRORS =====*/
void		display_error_tokens(char *error, char c);
void		display_error_exec(char *error, char *str);

/* ==== GET_SET ==== */
char		*get_path(char *path);
char		***get_copy(char **copy);
char		**get_paths(char **paths);
t_tree		*get_tree(t_tree *tree);
t_minishell	*get_minishell(t_minishell *shell);

//UTILS
void		init_shell(t_minishell *shell);
void		init_structs(t_minishell *shell);
void		processor(t_minishell *shell);
void		found_sintaxe(char *str, t_token **token_tail, t_token **token_h);
t_token		*get_last_node(t_token **list);
t_token		*get_first_node(t_token **list);
int			get_list_size(t_token *list);

/* EXCLUIR AO FINAL DO PROJETO */
void		print_list(t_token **lst);
void		print_tree(t_tree *tree);


#endif
