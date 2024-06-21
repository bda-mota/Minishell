#include "../includes/minishell.h"

static char	*find_type(int type);

void	print_list(t_token **lst)
{
	t_token	*current;
	char	*type;

	type = NULL;
	current = *lst;
	while (current)
	{
		printf("token: %s\n", current->content);
		type = find_type(current->type);
		printf("type: %s\n", type);
		printf("- - - - - - - - - - - - - - \n");
		current = current->next;
	}
}

void	print_redir(t_redir *redirs)
{
	t_redir	*current;

	current = redirs;
	while (current)
	{
		printf("fd: %d\n", current->fd);
		printf("type: %d\n", current->type);
		current = current->next;
	}
}

static char	*find_type(int type)
{
	char	*str;

	str = NULL;
	if (type == PIPE)
		str = "PIPE";
	else if (type == INPUT)
		str = "INPUT";
	else if (type == OUTPUT)
		str = "OUTPUT";
	else if (type == WORD)
		str = "WORD";
	else if (type == HEREDOC)
		str = "HEREDOC";
	else if (type == APPEND)
		str = "APPEND";
	else if (type == DOUBLE)
		str = "DOUBLE";
	else if (type == SIMPLE)
		str = "SIMPLE";
	else if (type == BLOCK)
		str = "BLOCK";
	else if (type == ARCHIVE)
		str = "ARCHIVE";
	else if (type == DELIMITER)
		str = "DELIMITER";
	return (str);
}

void	print_tree_main(t_tree *tree)
{
	print_tree_aux(tree, 0, "root");
}

void	print_tree_aux(t_tree *tree, int depth, const char *relation)
{
	int	i;

	i = 0;
	if (tree == NULL)
		return ;
	print_tree_aux(tree->right, depth + 1, "right");
	while (i < depth)
	{
		printf("  ");
		i++;
	}
	printf("(%s) %s\n", relation, tree->content);
	print_tree_aux(tree->left, depth + 1, "left");
}
