#ifndef TOKEN_H
# define TOKEN_H

# include "../libft/src/libft.h"
# include "structs.h"

void	insert_token(t_token **token, t_token *new_node);
t_token	*create_token(char *content, int type);
void	init_token(t_token **token);
void	deallocate_lst(t_token **token);
void	remove_first(t_token **token);
int		catalog_inputs(char *c, size_t *i);
void	tokenizer(t_minishell *shell);
void	handle_quotes(t_token **token, char *input, size_t *i);
void	handle_double(t_token **token, char *input, size_t *i, size_t size);
void	handle_simple(t_token **token, char *input, size_t *i, size_t size);
void	handle_word(t_token **token, char *input, size_t *i);
void	handle_pipe(t_token **token, char *input, size_t *i);
void	handle_input(t_token **token, char *input, size_t *i);
void	handle_output(t_token **token, char *input, size_t *i);
void	handle_append(t_token **token, char *input, size_t *i);
void	handle_heredoc(t_token **token, char *input, size_t *i);
void	handle_block(t_token **token, char *input, size_t *i);

/**** SEPARATORS - AUXILIARS ****/
int		check_blocks(char *input);
int		check_blocks_aux(char *input);
int		check_sintax(char *input);
int		check_untreatable(char *input);
int		check_quotes(char *input);
int		check_quotes_aux(char *input, int *i, char c);
int		count_double_quote(char *input, size_t *i);
int		count_simple_quote(char *input, size_t *i);
int		significant_tokens(t_token *tokens);

/* REARRANGE */
void	inspect_types(t_token **tokens);
void	rearrange_tokens(t_token **tokens);
int		check_redirects_on_pipeline(t_token **tokens);
int		check_pipeline(t_token **tokens);
t_token	*get_last_node_of_pipeline(t_token **tokens);
t_token	*get_first_node_of_pipeline(t_token **tokens);
t_token	*split_list(t_token **tokens);
t_token	*get_first_word(t_token **tokens);

/* VARIABLE_EXPANSION */

char	*find_variable(char *content, int *i, char **env_copy, char *data_var);
void	expand_variable(t_token **token, char **env_copy);
char	*my_getenv(char **env_copy, char *var);
char	*aux_expand_variable(char *content, char **env_copy);

#endif
