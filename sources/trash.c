/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:17:58 by bsantana          #+#    #+#             */
/*   Updated: 2024/06/04 18:43:30 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	print_tree(t_tree *tree)
{
	if (tree == NULL)
		return ;
	print_tree(tree->left);
	printf("%s\n", tree->content);
	print_tree(tree->right);
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
	else if (type == COMMAND)
		str = "COMMAND";
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

// Função principal para imprimir a árvore
