#include "../../includes/minishell.h"

//verificar se para mais de um heredoc precisamos ir trocando o nome
//incluir sinais Ctrl+D e Ctrl+C
static void	write_on_heredoc(char *line, int fd_heredoc);

void	heredoc(t_token **token)
{
	t_token	*heredoc;
	char	*line;
	int		fd_heredoc;

	while (!has_heredoc(*token))
	{
		heredoc = get_heredoc(*token);
		if (!heredoc)
			return ;
		fd_heredoc = open("/tmp/heredoc.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
		while (1)
		{
			line = readline("> ");
			if (!line)
				break ;
			if (!ft_strcmp(line, heredoc->next->content))
				break ;
			write_on_heredoc(line, fd_heredoc);
		}
		free(line);
		close(fd_heredoc);
		remove_heredoc(token, &heredoc, "/tmp/heredoc.txt");
	}
}

static void	write_on_heredoc(char *line, int fd_heredoc)
{
	write(fd_heredoc, line, ft_strlen(line));
	write(fd_heredoc, "\n", 1);
	free(line);
}
