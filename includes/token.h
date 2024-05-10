#ifndef TOKEN_H
# define TOKEN_H

# include "../libft/src/libft.h"
# include "structs.h"


void	insert_token(t_token **token, t_token *new_node);
t_token	*create_token(char *content, int type);

/**** linked list ****/

/*
 * Initializes a list of tokens.
 *
 * tail: pointer to the pointer to the last node in the list of tokens.
 * head: pointer to the head pointer of the token list.
 */
void	init_token(t_token **token);

/*
 * Releases the memory allocated to each node in the list and the list itself.
 */
void	deallocate_lst(t_token **token);

/*
 * Adds a new node to the token list.
 *
 * token_head: pointer to the head pointer of the token list.
 * content: content to be inserted into the new node.
 */
//void	insert_token(t_token **token, char *content, int type);

/*
 * Removes the first node from the token list.
 */
void	remove_first(t_token **token);

/**** inputs ****/

/*
 * Checks and classifies the type of input supplied.
 *
 * Parameters:
 * c: pointer to the string containing the input to be sorted.
 * i: pointer to the current index within the input string.
 *
 * Return:
 * Returns the input type.
 */
int		catalog_inputs(char *c, size_t *i);

/*
 * Identifies the type of entry to insert into the token list.
 */
void	course_inputs(t_token **token, char *input);

/**** SEPARATORS ****/

/*
 * Handle the processing of a quote in the
 * input and insert it into the token list.
 */
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


/*
 * Checks if there is a double quote (") in the current
 * position in the 'input' string. If a double quote is found,
 * the function counts the number of characters between the double
 * quotes, including the quotes themselves.
 * The total length of the string is returned.
*/
int		count_double_quote(char *input, size_t *i);
int		count_simple_quote(char *input, size_t *i);
int     significant_tokens(t_token *tokens);

#endif
