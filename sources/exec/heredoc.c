#include "../../includes/minishell.h"

static void	write_on_heredoc(char *line, int fd_heredoc);
static void	finish_heredoc(t_token **heredoc, int *fd, char *line, char *file);

void	heredoc(t_token **token)
{
	t_token	*heredoc;
	char	*file;
	char	*line;
	int		fd_heredoc;

	heredoc = *token;
	heredoc = find_heredoc(&heredoc);
	while (heredoc)
	{
		if (!heredoc)
			return ;
		file = generate_file_name();
		fd_heredoc = open_heredoc(file);
		signal_heredoc();
		while (1 && fd_heredoc != -1)
		{
			line = readline("> ");
			if (!line)
				break ;
			if (ft_strcmp(line, heredoc->next->content) == 0)
				break ;
			write_on_heredoc(line, fd_heredoc);
		}
		finish_heredoc(&heredoc, &fd_heredoc, line, file);
		heredoc = find_heredoc(&heredoc->next);
	}
}

static void	write_on_heredoc(char *line, int fd_heredoc)
{
	write(fd_heredoc, line, ft_strlen(line));
	write(fd_heredoc, "\n", 1);
	free(line);
}

static void	finish_heredoc(t_token **heredoc, int *fd, char *line, char *file)
{
	close(*fd);
	free(line);
	update_heredoc(heredoc, file);
}

int	open_heredoc(char *file)
{
	int	fd;

	fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd < 0)
	{
		ft_printf_fd(STDERR_FILENO, "Babyshell: %s\n", strerror(errno));
		return (-1);
	}
	return (fd);
}
