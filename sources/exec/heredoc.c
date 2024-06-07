#include "../../includes/minishell.h"

//verificar se para mais de um heredoc precisamos ir trocando o nome
//incluir sinais Ctrl+D, Ctrl+C e Ctrl+/
static void	write_on_heredoc(char *line, int fd_heredoc);
//static void	finish_heredoc(t_token **heredoc, int *fd, char *line, char *file);

void	heredoc(t_token **token)
{
	t_token	*heredoc;
	char	*file;
	char	*line;
	int		fd_heredoc;

	heredoc = find_heredoc(*token);
	while (heredoc)
	{
		if (!heredoc)
			return ;
		file = generate_file_name();
		fd_heredoc = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
		while (1)
		{
			line = readline("> ");
			if (!line)
				break ;
			if (!ft_strcmp(line, heredoc->next->content))
				break ;
			write_on_heredoc(line, fd_heredoc);
		}
		close(fd_heredoc);
		free(line);
		update_heredoc(&heredoc, file);
		heredoc = find_heredoc(heredoc->next);
	}
}

static void	write_on_heredoc(char *line, int fd_heredoc)
{
	write(fd_heredoc, line, ft_strlen(line));
	write(fd_heredoc, "\n", 1);
	free(line);
}
/*
static void	finish_heredoc(t_token **heredoc, int *fd, char *line, char *file)
{
	close(*fd);
	free(line);
	update_heredoc(heredoc, file);
	*heredoc = find_heredoc((*heredoc)->next);
}*/


