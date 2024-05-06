#include "libft.h"

int	ft_putchar_fd(char c, int fd)
{
	int	result;

	result = write(fd, &c, 1);
	return (result);
}
