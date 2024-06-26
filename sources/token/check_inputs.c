/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:48:30 by bda-mota          #+#    #+#             */
/*   Updated: 2024/06/21 14:48:32 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	display_error_tokens(char *error, char c)
{
	if (ft_strcmp(error, "sintaxe") == 0)
		ft_printf_fd(STDERR_FILENO,
			"babyshell: syntax error near unexpected token `%c´\n", c);
	if (ft_strcmp(error, "newline") == 0)
		ft_printf_fd(STDERR_FILENO,
			"babyshell: syntax error near unexpected token `newline´\n", c);
	get_status(2);
}

int	check_quotes(char *input)
{
	int	i;
	int	d_quotes;
	int	s_quotes;

	i = 0;
	d_quotes = 0;
	s_quotes = 0;
	while (input[i])
	{
		if (input[i] == '"')
			d_quotes = check_quotes_aux(input, &i, '"');
		if (input[i] == '\'')
			s_quotes = check_quotes_aux(input, &i, '\'');
		if (input[i])
			i++;
	}
	if (d_quotes % 2 != 0)
		display_error_tokens("sintaxe", '"');
	else if (s_quotes % 2 != 0)
		display_error_tokens("sintaxe", '\'');
	else
		return (1);
	return (0);
}

int	check_quotes_aux(char *input, int *i, char c)
{
	int	quote;

	quote = 1;
	(*i)++;
	if (c == '"')
	{
		while (input[*i] && input[*i] != '"')
			(*i)++;
		if (input[*i] == '"')
			quote++;
	}
	else if (c == '\'')
	{
		while (input[*i] && input[*i] != '\'')
			(*i)++;
		if (input[*i] == '\'')
			quote++;
	}
	return (quote);
}

int	check_untreatable(char *input)
{
	if (ft_strstr(input, "<<<"))
		display_error_tokens("sintaxe", '<');
	else if (ft_strstr(input, ">>>"))
		display_error_tokens("sintaxe", '>');
	else if (ft_strstr(input, "|||"))
		display_error_tokens("sintaxe", '|');
	else
		return (1);
	return (0);
}
