#include "../../includes/minishell.h"

int	has_heredoc(t_token *token)
{
	t_token	*curr;

	curr = token;
	while (curr)
	{
		if (curr->type == HEREDOC)
			return (1);
		curr = curr->next;
	}
	return (0);
}

t_token	*get_heredoc(t_token *token)
{
	t_token	*curr;

	curr = token;
	while (curr)
	{
		if (curr->type == HEREDOC)
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}

//verificar se para mais de um heredoc precisamos ir trocando o nome
//incluir sinais Ctrl+D e Ctrl+C
void	heredoc(t_token *token)
{
	t_token	*heredoc;
	char	*line;
	int		fd_heredoc;

	heredoc = get_heredoc(token);
	if (!heredoc)
		return ;
	fd_heredoc = open("/tmp/heredoc.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (ft_strcmp(line, heredoc->next->content) == 0)
		{
			free(line);
			break ;
		}
		write(fd_heredoc, line, ft_strlen(line));
		write(fd_heredoc, "\n", 1);
		free(line);
	}
	close(fd_heredoc);
	remove_heredoc(heredoc);
}

//função para remover o heredoc e o delimitador
//procurar se há mais heredocs
void	remove_heredoc(t_token *token)
{
	t_token	*curr;
	t_token	*aux;

	aux = token;
	curr = token;
	if (curr->prev && curr->next->next)
	{
		curr->prev->next = curr->next->next;
		curr->next->next->prev = curr->prev;
	}
	else if (curr->prev)
		curr->prev->next = NULL;
	else if (curr->next->next)
		curr->next->next->prev = NULL;
	free(aux->next->content);
	free(aux->next);
	free(aux->content);
	free(aux);
}

// loop se houver mais de um heredoc
/*
while (has_heredoc(token))
{
	heredoc = get_heredoc(token);
	if (!heredoc)
		return ;
	fd_heredoc = open("/tmp/heredoc.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (ft_strcmp(line, heredoc->next->content) == 0)
		{
			free(line);
			break ;
		}
		write(fd_heredoc, line, ft_strlen(line));
		write(fd_heredoc, "\n", 1);
		free(line);
	}
	close(fd_heredoc);
	remove_heredoc(heredoc);
}
*/
