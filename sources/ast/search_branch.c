#include "../../includes/minishell.h"

//procura se há pipe primeiro, depois redir e se não tiver retorna null
//curr[0] = left
//curr[1] =	metacharacter
//curr[2] = right
//se for pipe, ponteiro para o left e right normal
//se for redir, ponteiro curr[2] vai ser igual ao arquivo e curr[0] vai ser igual à frase modificada
t_token	**search_branchs(t_token **tokens)
{
	t_token	**curr;
	t_token	*meta;

	meta = search_pipe(tokens);
	curr = ft_calloc(3, sizeof(t_token *));
	if (meta)
	{
		curr[0] = meta->prev;
		curr[0]->next = NULL;
		curr[1] = meta;
		curr[2] = meta->next;
		curr[2]->prev = NULL;
		return (curr);
	}
	meta = search_redirs(tokens);
	if (meta)
	{
		curr[0] = new_redir_list(&meta);
		curr[1] = meta;
		curr[2] = meta->next;
		return (curr);
	}
	curr[0] = NULL;
	curr[1] = put_all_together(tokens);
	curr[2] = NULL;
	return (curr);
}

//retorna um ponteiro para o nó da lista que tem o pipe
//lendo de trás para frente
t_token	*search_pipe(t_token **tokens)
{
	t_token	*curr;

	curr = get_last_node(tokens);
	while (curr)
	{
		if (curr->type == PIPE)
			return (curr);
		curr = curr->prev;
	}
	return (NULL);
}

//retorna um ponteiro para o nó da lista que tem o redir
//lendo do começo para o final
t_token	*search_redirs(t_token **tokens)
{
	t_token	*curr;

	curr = get_first_node(tokens);
	while (curr)
	{
		if (is_redir_or_heredoc(&curr))
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}

//vai receber o nó do meta, desvincular ele e o arquivo dele da lista e
//retorna o ínicio da lista para curr [0]
t_token	*new_redir_list(t_token **token_list)
{
	t_token	*curr;

	curr = *token_list;
	if (curr->prev)
		curr->prev->next = curr->next->next;
	if (curr->next->next)
		curr->next->next->prev = curr->prev;
	if (curr->prev == NULL)
		return (NULL);
	while (curr->prev && curr->prev->type != PIPE)
		curr = curr->prev;
	return (curr);
}
