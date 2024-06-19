#ifndef TOKEN_H
# define TOKEN_H

# include "../libft/src/libft.h"
# include "structs.h"

/* ==== LINKED LIST ==== */
void	init_token(t_token **token);
void	deallocate_lst(t_token **token);
void	remove_first(t_token **token);
void	insert_token(t_token **token, t_token *new_node);
t_token	*create_token(char *content, int type);

/* ==== TOKEN ==== */
int		catalog_inputs(char *c, size_t *i);
void	tokenizer(t_minishell *shell);

/* ==== HANDLE INPUTS ==== */
void	handle_one(t_token **token, char *input, size_t *i);
void	handle_two(t_token **token, char *input, size_t *i);
void	handle_word(t_token **token, char *input, size_t *i);

/* ====  CHECK - INPUTS ==== */
int		check_untreatable(char *input);
int		check_quotes(char *input);
int		check_quotes_aux(char *input, int *i, char c);

/* ==== CHECK GRAMMAR ==== */
int		check_sintax(char *input);
int		check_grammar(t_token **token);
int		is_invalid_pipe(t_token *curr);
int		is_invalid_redir_or_heredoc(t_token *curr);

/* ==== REARRANGE ==== */
void	inspect_types(t_token **tokens);
void	rearrange_tokens(t_token **tokens);
int		check_pipeline(t_token **tokens);
t_token	*get_last_node_of_pipeline(t_token **tokens);
t_token	*get_first_node_of_pipeline(t_token **tokens);
t_token	*split_list(t_token **tokens);
t_token	*get_first_word(t_token **tokens);

/* ==== VARIABLE_EXPANSION ==== */

char	*find_variable(char *content, int *i, char **env_copy, char *data_var);
void	expand_variable(t_token **token, char **env_copy);
char	*ft_getenv(char **env_copy, char *var);
char	*process_character(char *content, int i, char *data_var, char quote);
char	*aux_expand_variable(char *content, char **env_copy);

#endif
