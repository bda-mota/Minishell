#include "../../includes/minishell.h"

int	has_heredoc(t_token *token)
{
	t_token	*curr;

	curr = token;
	while (curr)
	{
		if (curr->type == HEREDOC)
			return (0);
		curr = curr->next;
	}
	return (1);
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
void	heredoc(t_token **token)
{
	t_token	*heredoc;
	char	*line;
	int		fd_heredoc;

	heredoc = get_heredoc(*token);
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
	remove_heredoc(token, &heredoc, "/tmp/heredoc.txt");
}

//função para remover o heredoc e o delimitador
//procurar se há mais heredocs
void	remove_heredoc(t_token **token, t_token **heredoc, char *path)
{
	t_token	*delimiter;

	delimiter = (*heredoc)->next;
	if (delimiter->next)
	{
		(*heredoc)->next = delimiter->next;
		delimiter->next->prev = *heredoc;
	}
	else
		(*heredoc)->next = NULL;
	free(delimiter->content);
	free(delimiter);
	if (!(*heredoc)->prev && !(*heredoc)->next)
		deallocate_lst(token);
	else
	{
		(*heredoc)->content = ft_strdup(path);
		(*heredoc)->type = ARCHIVE;
	}
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
