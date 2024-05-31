#include "../../includes/minishell.h"

void build_tree(t_tree **root, t_token **tokens)
{
 	t_token **branchs;

	branchs = search_branchs(tokens);
	if (branchs[0] == NULL && branchs[2] == NULL)
	{
		*root = create_branch(branchs, WORD);
		free(branchs);
		return ;
	}
 	if (branchs && (branchs[1]->type == PIPE))
	{
		*root = create_branch(branchs, PIPE);
		build_tree(&((*root)->left), &branchs[0]);
		build_tree(&((*root)->right), &branchs[2]);
		free(branchs);
		return ;
	}
	else if (branchs && is_redir_or_heredoc(&branchs[1]))
	{
		*root = create_branch(branchs, REDIRECT);
		tokens = &branchs[1];
		if (branchs[0] != NULL)
			build_tree(&((*root)->left), tokens);
		free(branchs);
		return ;
	}
}
