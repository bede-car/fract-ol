/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer_adress.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 02:28:39 by bede-car          #+#    #+#             */
/*   Updated: 2022/09/27 19:09:37 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer_adress(va_list arguments)
{
	int		written;
	char	*pointer;
	size_t	argp;

	written = 0;
	argp = (va_arg(arguments, size_t));
	if (argp == 0)
	{
		ft_putstr_fd("(nil)", 1);
		written += 5;
	}
	else
	{
		pointer = ft_pitoa(argp);
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(pointer, 1);
		written += ft_strlen(pointer) + 2;
		free(pointer);
	}
	return (written);
}

int	ft_count_digp(unsigned long int n)
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

char	*ft_pitoa(unsigned long int n)
{
	char	*str;
	int		i;

	str = malloc((ft_count_digp(n)) + 1);
	if (!str)
		return (NULL);
	i = ft_count_digp(n) - 1;
	str[i + 1] = '\0';
	while (n >= 16)
	{
		if ((n % 16) < 10)
			str[i] = (n % 16) + '0';
		else
			str[i] = ((n % 16) + 'a') - 10;
		n /= 16;
		i--;
	}
	if (n <= 16)
	{
		if (n < 10)
			str[i] = n + '0';
		else
			str[i] = (n + 'a') - 10;
	}
	return (str);
}
