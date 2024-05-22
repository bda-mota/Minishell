#include "../../includes/minishell.h"

int	is_metha(t_token *token)
{
	if (token->type == APPEND || token->type == HEREDOC
		|| token->type == INPUT || token->type == OUTPUT)
		return (1);
	return (0);
}

void	down_tree(t_tree **root)
{
	if (*root == NULL)
		return ;
	down_tree(&(*root)->left);
	down_tree(&(*root)->right);
	if ((*root)->content)
		free((*root)->content);
	free(*root);
	*root = NULL;
}

t_token	*put_all_together(t_token **token)
{
	t_token	*curr;
	t_token	*new;

	curr = get_first_node(token);
	if (!curr)
		return (NULL);
	new = ft_calloc(sizeof(t_token), 1);
	if (!new)
		return (NULL);
	new->content = strdup("");
	aux_pull_all_together(&new, &curr);
	return (new);
}

void	aux_pull_all_together(t_token **new, t_token **curr)
{
	char	*aux_str;
	t_token	*temp;

	temp = *curr;
	while (temp)
	{
		aux_str = (*new)->content;
		(*new)->content = ft_strjoin(aux_str, temp->content);
		free(aux_str);
		if (temp->next)
		{
			aux_str = (*new)->content;
			(*new)->content = ft_strjoin(aux_str, " ");
			free(aux_str);
		}
		temp = temp->next;
	}
	while (*curr)
	{
		temp = (*curr)->next;
		free((*curr)->content);
		free(*curr);
		*curr = temp;
	}
}

void	traverse_tree(t_tree **root)
{
	if (*root == NULL)
		return ;
	traverse_tree(&(*root)->left);
	traverse_tree(&(*root)->right);
	//if ((*root)->content)
	//	ft_printf_fd("%s\n", (*root)->content, 1);
}
