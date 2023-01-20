/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_decimal_integer.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 03:23:27 by bede-car          #+#    #+#             */
/*   Updated: 2022/09/27 19:12:58 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned_decimal_integer(va_list arguments)
{
	int		arg;
	int		written;
	char	*u;

	arg = (va_arg(arguments, unsigned int));
	written = 0;
	u = ft_uitoa((unsigned int)arg);
	ft_putstr_fd(u, 1);
	written += ft_strlen(u);
	free(u);
	return (written);
}

int	ft_count_udig(unsigned int n)
{
	int	c;

	c = 0;
	while (n >= 10)
	{
		n /= 10;
		c++;
	}
	if (n < 10)
		c++;
	return (c);
}

char	*ft_uitoa(unsigned int n)
{
	char	*str;
	int		i;

	str = malloc((ft_count_udig(n)) + 1);
	if (!str)
		return (NULL);
	i = ft_count_udig(n) - 1;
	str[i + 1] = '\0';
	while (n >= 10)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	if (n <= 9)
		str[i] = n + '0';
	return (str);
}
