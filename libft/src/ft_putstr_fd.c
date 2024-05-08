/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:41:19 by bda-mota          #+#    #+#             */
/*   Updated: 2024/05/08 11:41:21 by bda-mota         ###   ########.fr       */
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
