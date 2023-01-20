/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_hexadecimal_integer.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 03:43:51 by bede-car          #+#    #+#             */
/*   Updated: 2022/09/27 19:17:00 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned_hexadecimal_integer(va_list arguments, char format)
{
	int		index;
	int		written;
	int		arg;
	char	*hex;

	index = 0;
	written = 0;
	arg = (va_arg(arguments, int));
	hex = ft_hitoa(arg);
	if (format == 'X')
	{
		while (hex[index])
		{
			if (ft_isalpha(hex[index]))
				hex[index] = ft_toupper(hex[index]);
			index++;
		}
	}
	ft_putstr_fd(hex, 1);
	written += ft_strlen(hex);
	free(hex);
	return (written);
}

int	ft_count_hdig(unsigned int n)
{
	int	c;

	c = 1;
	while (n >= 16)
	{
		n /= 16;
		c++;
	}
	return (c);
}

char	*ft_hitoa(unsigned int n)
{
	char	*str;
	int		index;

	str = malloc((ft_count_hdig(n)) + 1);
	if (!str)
		return (NULL);
	index = ft_count_hdig(n) - 1;
	str[index + 1] = '\0';
	while (n >= 16)
	{
		if ((n % 16) < 10)
			str[index] = (n % 16) + '0';
		else
			str[index] = ((n % 16) + 'a') - 10;
		n /= 16;
		index--;
	}
	if (n <= 16)
	{
		if (n < 10)
			str[index] = n + '0';
		else
			str[index] = (n + 'a') - 10;
	}
	return (str);
}
