/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed_decimal_integer.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 03:00:28 by bede-car          #+#    #+#             */
/*   Updated: 2022/09/27 19:10:15 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_signed_decimal_integer(va_list arguments)
{
	int		arg;
	char	*decimal;
	int		written;

	arg = (va_arg(arguments, int));
	decimal = ft_itoa(arg);
	written = 0;
	ft_putstr_fd(decimal, 1);
	written += ft_strlen(decimal);
	free(decimal);
	return (written);
}
