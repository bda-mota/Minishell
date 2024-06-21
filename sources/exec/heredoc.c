#include "../../includes/minishell.h"

static void	write_on_heredoc(char *line, int fd_heredoc);
static void	finish_heredoc(t_token **heredoc, int *fd, char *line, char *file);
static char	*expand_heredoc(char *line, int *pos);

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

static void	write_on_heredoc(char *line, int fd_heredoc)
{
	int		i;
	char	*variable;

	i = 0;
	while (line[i])
	{
		if (line[i] == '$' && line[i + 1] != '\0')
		{
			variable = expand_heredoc(line, &i);
			if (variable != NULL)
				write(fd_heredoc, variable, ft_strlen(variable));
		}
		if (line[i])
			write(fd_heredoc, &line[i], 1);
		i++;
	}
	write(fd_heredoc, "\n", 1);
	free(line);
}

static void	finish_heredoc(t_token **heredoc, int *fd, char *line, char *file)
{
	close(*fd);
	free(line);
	update_heredoc(heredoc, file);
}

static char	*expand_heredoc(char *line, int *pos)
{
	int		i;
	int		j;
	char	**env_copy;
	char	*var;

	i = 0;
	j = 0;
	var = ft_calloc(sizeof(char), ft_strlen(line) + 1);
	if (!var)
		return (NULL);
	env_copy = *get_env_copy(NULL);
	(*pos)++;
	while (line[*pos] && line[*pos] != ' '
		&& line[*pos] != '\'' && line[*pos] != '"')
	{
		var[j] = line[*pos];
		j++;
		(*pos)++;
	}
	while (env_copy[i])
	{
		if (ft_strncmp(env_copy[i], var, j) == 0 && env_copy[i][j] == '=')
		{
			free(var);
			return (env_copy[i] + j + 1);
		}
		i++;
	}
	free(var);
	return (NULL);
}
