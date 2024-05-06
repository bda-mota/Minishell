#include "libft.h"

int	ft_flags(char flag, va_list args)
{
	if (flag == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	if (flag == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	if (flag == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}

int	ft_printf_fd(const char *type_format, ...)
{
	va_list	args;
	int		i;
	int		result;

	i = 0;
	result = 0;
	if (!type_format)
		return (-1);
	va_start(args, type_format);
	while (type_format[i])
	{
		if (type_format[i] == '%' && type_format[i + 1] != '\0')
			result += ft_flags(type_format[++i], args);
		else
			result += ft_putchar_fd(type_format[i], 1);
		i++;
	}
	va_end(args);
	return (result);
}
