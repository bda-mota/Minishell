#include "../../includes/minishell.h"

t_redir	*create_redir(int *fd, int type)
{
	t_redir	*new_redir;

	new_redir = malloc(sizeof(t_redir));
	if (!new_redir)
		return (NULL);
	new_redir->fd = *fd;
	new_redir->type = type;
	new_redir->next = NULL;
	return (new_redir);
}

void	insert_redir(t_redir **redirs, t_redir *new_redir)
{
	t_redir	*curr;

	curr = *redirs;
	if (!*redirs)
		*redirs = new_redir;
	else
	{
		while (curr->next)
			curr = curr->next;
		curr->next = new_redir;
	}
}

void	deallocate_redirs(t_redir **redirs)
{
	t_redir	*curr;
	t_redir	*temp;

	if (!*redirs)
		return ;
	curr = *redirs;
	while (curr)
	{
		temp = curr->next;
		free(curr);
		curr = temp;
	}
	*redirs = NULL;
}
