/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:59:02 by bede-car          #+#    #+#             */
/*   Updated: 2022/09/27 19:11:36 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(va_list arguments)
{
	int		written;
	char	*arg;

	written = 0;
	arg = (va_arg(arguments, char *));
	if (!arg)
	{
		ft_putstr_fd("(null)", 1);
		written += 6;
	}
	else
	{
		ft_putstr_fd(arg, 1);
		written = ft_strlen(arg);
	}
	return (written);
}
