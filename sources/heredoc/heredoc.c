/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:48:00 by bda-mota          #+#    #+#             */
/*   Updated: 2024/06/21 14:48:02 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
		signal_heredoc();
		file = generate_file_name();
		fd_heredoc = open_heredoc(file);
		remove_quotes_from_delim(heredoc->next->content);
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

void	remove_quotes_from_delim(char *delimiter)
{
	int		i;
	char	quote;

	i = 0;
	while (delimiter[i] != 0)
	{
		if (delimiter[i] == '\'' || delimiter[i] == '"')
		{
			quote = delimiter[i];
			ft_memmove(&delimiter[i], &delimiter[i + 1],
				ft_strlen(&delimiter[i]));
			while (delimiter [i] != quote)
				i++;
			ft_memmove(&delimiter[i], &delimiter[i + 1],
				ft_strlen(&delimiter[i]));
		}
		else
			i++;
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

void	write_on_heredoc(char *line, int fd_heredoc)
{
	int		i;
	char	*variable;

	i = 0;
	while (line[i])
	{
		if (line[i] == '$' && line[i + 1] != '\0')
		{
			i++;
			variable = expand_heredoc(line, &i);
			if (variable != NULL)
				write(fd_heredoc, variable, ft_strlen(variable));
		}
		else
		{
			if (line[i])
				write(fd_heredoc, &line[i], 1);
			i++;
		}
	}
	write(fd_heredoc, "\n", 1);
	free(line);
}
