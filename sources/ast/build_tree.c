#include "../../includes/minishell.h"

void	build_tree(t_tree **root, t_token **tokens)
{
	t_token	**branchs;

	branchs = search_branchs(tokens);
	if (branchs[0] == NULL && branchs[2] == NULL)
	{
		*root = create_branch(branchs, WORD);
		free(branchs);
	}
	else if (branchs && (branchs[1]->type == PIPE))
	{
		*root = create_branch(branchs, PIPE);
		build_tree(&((*root)->left), &branchs[0]);
		build_tree(&((*root)->right), &branchs[2]);
		free(branchs);
	}
	else if (branchs && is_redir_or_heredoc(&branchs[1]))
	{
		*root = create_branch(branchs, REDIRECT);
		tokens = &branchs[0];
		if (branchs[0] != NULL)
			build_tree(&((*root)->left), tokens);
		free(branchs);
	}
	return ;
}

t_tree	*create_branch(t_token **token_list, int type)
{
	t_tree	*new_branch;

	new_branch = ft_calloc(sizeof(t_tree), 1);
	if (!new_branch)
		return (NULL);
	new_branch->type = type;
	new_branch->content = ft_strdup(token_list[1]->content);
	free(token_list[1]->content);
	free(token_list[1]);
	if (type == REDIRECT)
	{
		new_branch->right = ft_calloc(1, sizeof(t_tree));
		if (!new_branch->right)
		{
			free(new_branch->content);
			free(new_branch);
			return (NULL);
		}
		new_branch->right->type = ARCHIVE;
		new_branch->right->content = ft_strdup(token_list[2]->content);
		free(token_list[2]->content);
		free(token_list[2]);
	}
	return (new_branch);
}
