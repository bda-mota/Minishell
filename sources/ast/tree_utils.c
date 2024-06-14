#include "../../includes/minishell.h"

void	down_tree(t_tree **root)
{
	if (*root == NULL)
		return ;
	down_tree(&(*root)->left);
	down_tree(&(*root)->right);
	if ((*root)->content && ft_strncmp((*root)->content, "/tmp/heredoc", 12) == 0)
		unlink((*root)->content);
	if ((*root)->content)
		free((*root)->content);
	free(*root);
	*root = NULL;
}

t_token	*put_all_together(t_token **token)
{
	t_token	*curr;
	t_token	*new;

	if (!token || !*token)
		return (NULL);
	curr = get_first_node(token);
	if (!curr)
		return (NULL);
	new = ft_calloc(sizeof(t_token), 1);
	if (!new)
		return (NULL);
	new->content = strdup("");
	new->type = curr->type;
	aux_pull_all_together(&new, &curr);
	return (new);
}

void	aux_pull_all_together(t_token **new, t_token **curr)
{
	char	*aux_str;
	t_token	*temp;

	temp = *curr;
	while (temp && temp->type != PIPE)
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

