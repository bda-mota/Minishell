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

t_token	*find_heredoc(t_token *token)
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

void	update_heredoc(t_token **heredoc, char *file)
{
	t_token	*delimiter;

	delimiter = (*heredoc)->next;
	free(delimiter->content);
	delimiter->content = file;
}

char	*generate_file_name(void)
{
	char		*dir_name;
	char		*nbr;
	char		*file_name;
	static int	i;

	dir_name = "/tmp/heredoc";
	nbr = ft_itoa(i);
	file_name = ft_strjoin(dir_name, nbr);
	free(nbr);
	i++;
	return (file_name);
}

