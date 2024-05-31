#include "../../includes/minishell.h"

void build_tree(t_tree **root, t_token **tokens)
{
 	t_token **branchs;

	if (!tokens || !*tokens)
	{
        *root = NULL;
        return;
    }
	branchs = search_branchs(tokens);
	if (branchs[1] == NULL)
		return ;
	if (branchs[0] == NULL && branchs[2] == NULL)
	{
		*root = create_branch(branchs, WORD);
		return ;
	}
 	if (branchs && (branchs[1]->type == PIPE))
	{
		*root = create_branch(branchs, PIPE);
		build_tree(&((*root)->left), &branchs[0]);
		build_tree(&((*root)->right), &branchs[2]);
		free(branchs);
		return;
	}
	else if (branchs && is_redir_or_heredoc(&branchs[1]))
	{
		*root = create_branch(branchs, REDIRECT);
		tokens = &branchs[1];
		build_tree(&((*root)->left), tokens);
		free(branchs);
		return;
	}
}

// void	remove_pipe_node(t_token **tokens)
// {
// 	t_token *curr;

// 	curr = get_last_node(tokens);
// 	while (curr)
// 	{
// 		if (curr->type == PIPE)
// 		{
// 			if (curr->prev)
// 				curr->prev->next = curr->next;
// 			if (curr->next)
// 				curr->next->prev = curr->prev;
// 			return;
// 		}
// 		curr = curr->prev;
// 	}
// }
