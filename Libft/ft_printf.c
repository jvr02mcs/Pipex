#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

static int	ft_putptr(unsigned long n, char *upporlow)
{
	int	bytes;
	int	tst;

	bytes = 0;
	tst = bytes;
	if (n >= 16)
		bytes += ft_putptr((n / 16), upporlow);
	else
		bytes += ft_putstr_fd("0x", 1);
	if (tst > bytes)
		return (-1);
	bytes += ft_putchar_fd(upporlow[n % 16], 1);
	return (bytes);
}

static int	ft_putnbr_base(long n, int base, char *upporlow)
{
	int	bytes;
	int	tst;

	bytes = 0;
	tst = bytes;
	if (base == 16)
	{
		if (n >= 16)
			bytes += ft_putnbr_base((n / 16), 16, upporlow);
		if (tst > bytes)
			return (-1);
		bytes += ft_putchar_fd(upporlow[n % 16], 1);
	}
	if (base == 10)
	{
		if (n < 0)
		{
			n = -n;
			bytes += ft_putchar_fd('-', 1);
			if (tst > bytes)
				return (-1);
		}
		if (n >= 10)
			bytes += ft_putnbr_base(n / 10, 10, upporlow);
		if (tst > bytes)
			return (-1);
		bytes += ft_putchar_fd(n % 10 + '0', 1);
	}
	return (bytes);
}


static int	put(char c, va_list *argmnt)
{
	int	bytes;

	bytes = 0;
	if (c == 'c')
		bytes = ft_putchar_fd(va_arg(*argmnt, int), 1);
	else if (c == 's')
		bytes = ft_putstr_fd(va_arg(*argmnt, char *), 1);
	else if (c == 'd' || c == 'i')
		bytes = ft_putnbr_base(va_arg(*argmnt, int), 10, NULL);
	else if (c == 'X')
		bytes = ft_putnbr_base(va_arg(*argmnt, unsigned int), 16, "0123456789ABCDEF");
	else if (c == 'x')
		bytes = ft_putnbr_base(va_arg(*argmnt, unsigned int), 16, "0123456789abcdef");
	else if (c == 'u')
		bytes = ft_putnbr_base(va_arg(*argmnt, unsigned int), 10, NULL);
	else if (c == 'p')
		bytes = ft_putptr(va_arg(*argmnt, unsigned long), "0123456789abcdef");
	else
		bytes += ft_putchar_fd('%', 1);
	return (bytes);
}

int	ft_printf(char const *s, ...)
{
	va_list	args;
	int		bytes;
	int		tst;
	int		i;

	i = 0;
	bytes = 0;
	if (!s)
		return (0);
	va_start(args, s);
	while (s[i] != '\0')
	{
		tst = bytes;
		if (s[i] == '%')
			bytes = bytes + put(s[++i], &args);
		else
			bytes += ft_putchar_fd(s[i], 1);
		if (tst > bytes)
			break;
		i++;
	}
	va_end(args);
	return (bytes);
}