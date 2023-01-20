/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 21:07:25 by bede-car          #+#    #+#             */
/*   Updated: 2022/09/27 19:06:44 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		index;
	int		written;
	va_list	arguments;

	va_start(arguments, format);
	index = 0;
	written = 0;
	while (format[index] != 0)
	{
		if (format[index] != '%')
		{
			ft_putchar_fd(format[index], 1);
			written++;
		}
		else
		{
			index++;
			written += ft_check_specifier(format[index], arguments);
		}
		index++;
	}
	va_end(arguments);
	return (written);
}

int	ft_check_specifier(char format, va_list arguments)
{
	int	written;

	written = 0;
	if (format == 'c')
		written = print_character(arguments);
	else if (format == 's')
		written = print_string(arguments);
	else if (format == 'p')
		written = print_pointer_adress(arguments);
	else if (format == 'd' || format == 'i')
		written = print_signed_decimal_integer(arguments);
	else if (format == 'u')
		written = print_unsigned_decimal_integer(arguments);
	else if (format == 'x' || format == 'X')
		written = print_unsigned_hexadecimal_integer(arguments, format);
	else if (format == '%')
		written = write(1, "%", 1);
	else
	{
		ft_putchar_fd('%', 1);
		ft_putchar_fd(format, 1);
		written = 2;
	}
	return (written);
}
