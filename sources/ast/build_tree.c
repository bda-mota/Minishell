#include "../../includes/minishell.h"

static void	branch_aux(t_tree **branch, t_token **token, int type, int meta);

void	build_tree(t_tree **root, t_token **tokens)
{
	t_token	**branchs;

	branchs = search_branchs(tokens);
	if (branchs[0] == NULL && branchs[2] == NULL)
		*root = create_branch(branchs, WORD);
	else if (branchs && (branchs[1]->type == PIPE))
	{
		*root = create_branch(branchs, PIPE);
		build_tree(&((*root)->left), &branchs[0]);
		build_tree(&((*root)->right), &branchs[2]);
	}
	else if (branchs && is_redir_or_heredoc(&branchs[1]))
	{
		*root = create_branch(branchs, (branchs[1])->type);
		tokens = &branchs[0];
		if (branchs[0] != NULL)
			build_tree(&((*root)->left), tokens);
	}
	free(branchs);
}

t_tree	*create_branch(t_token **token_list, int type)
{
	t_tree	*new_branch;

	new_branch = ft_calloc(sizeof(t_tree), 1);
	if (!new_branch)
		return (NULL);
	branch_aux(&new_branch, token_list, type, 1);
	if (type == INPUT || type == OUTPUT || type == APPEND || type == HEREDOC)
	{
		new_branch->right = ft_calloc(1, sizeof(t_tree));
		if (!new_branch->right)
		{
			free(new_branch->content);
			free(new_branch);
			return (NULL);
		}
		branch_aux(&new_branch->right, token_list, type, 2);
	}
	return (new_branch);
}

static void	branch_aux(t_tree **branch, t_token **token, int type, int meta)
{
	if (meta == 1)
	{
		(*branch)->type = type;
		(*branch)->content = ft_strdup(token[1]->content);
		free(token[1]->content);
		free(token[1]);
	}
	else
	{
		(*branch)->type = ARCHIVE;
		(*branch)->content = ft_strdup(token[2]->content);
		free(token[2]->content);
		free(token[2]);
	}
}
