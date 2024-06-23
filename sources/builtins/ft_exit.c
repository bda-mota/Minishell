/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:45:52 by bda-mota          #+#    #+#             */
/*   Updated: 2024/06/21 20:54:20 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_exit_aux(char *args);
static int	contains_syntax_error(char *new);
static int	print_exit_error(char *new, char *error);
static char	*remove_quotes_exit(char *args);

int	ft_exit(char *args)
{
	t_minishell	shell;
	int			status;

	if (args != NULL)
		status = ft_exit_aux(args);
	else
		status = 0;
	if (status == 1)
		return (get_status(status));
	get_status(status);
	shell = *get_minishell(NULL);
	rl_clear_history();
	free_minishell(&shell);
	printf("exit\n");
	exit(status);
}

static int	ft_exit_aux(char *args)
{
	int		type;
	int		number;
	int		result;
	char	*new;

	new = remove_quotes_exit(args);
	number = ft_atoi(new);
	type = contains_syntax_error(new);
	free(new);
	if (type == 1)
		return (1);
	else if (type == 2)
		return (2);
	if (number >= 0 && number <= 255)
		return (number);
	result = number % 256;
	if (number < 0)
		result += 256;
	return (result);
}

static int	contains_syntax_error(char *new)
{
	int	i;
	int	len;
	int	sign;

	i = 0;
	sign = 0;
	while (*new && *new == '0')
		new++;
	len = ft_strlen(new);
	if ((len == 19 && ft_strncmp(new, "9223372036854775807", 19) > 0)
		|| (len == 20 && ft_strncmp(new, "-9223372036854775808", 20) > 0)
		|| (len > 20 && check_spaces(new) == 1))
		return (print_exit_error(new, "long"));
	while (new[i])
	{
		if (ft_issign(new[i]) == 1)
			sign++;
		if (ft_isspace(new[i]) == 1)
			return (print_exit_error(new, "arguments"));
		if (ft_isalpha(new[i]) == 1 || sign > 1)
			return (print_exit_error(new, "alpha"));
		i++;
	}
	return (0);
}

static int	print_exit_error(char *new, char *error)
{
	if (ft_strcmp(error, "long") == 0 || ft_strcmp(error, "alpha") == 0)
	{
		ft_printf_fd(STDIN_FILENO, "exit\n");
		ft_printf_fd(STDERR_FILENO,
			"babyshell: exit: %s: numeric argument required\n", new);
		return (2);
	}
	else
	{
		ft_printf_fd(STDIN_FILENO, "exit\n");
		ft_printf_fd(STDERR_FILENO, "babyshell: exit: too many arguments\n");
		rl_clear_history();
		return (1);
	}
}

static char	*remove_quotes_exit(char *args)
{
	int		i;
	int		j;
	int		len;
	char	*new_args;

	i = 0;
	j = 0;
	len = ft_strlen(args);
	new_args = ft_calloc(sizeof(char), len + 1);
	if (!new_args)
		return (NULL);
	while (args[i])
	{
		if (args[i] != '\'' && args[i] != '\"')
		{
			new_args[j] = args[i];
			j++;
		}
		i++;
	}
	return (new_args);
}
