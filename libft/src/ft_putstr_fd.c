/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:44:33 by bda-mota          #+#    #+#             */
/*   Updated: 2024/05/06 16:36:21 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	if (s == NULL)
		return (write(1, "(null)", 6));
	while (s && s[i] != 0)
	{
		result += write (fd, &s[i], 1);
		i++;
	}
	return (result);
}
